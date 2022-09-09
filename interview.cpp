#include <stdio.h>
#include <iostream>
#include <algorithm>

#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

void test();
void test2();
void test3();

int main()
{
    //difference between C and C++

    //C is procedure oriented, C++ object oriented
    //C:follows top down approach, C++:bottom up approach
    //C:does not support function or operator overloading
    //doesnot support virtual or friend function 

    //what are classes and objects?

    //class is user defined datatype with data members, member functions
    //objects are instance of a class. once it is created, it can operate on
    //data members and member functions

    //access modifiers

    //defines accessibility for the class members. private, public and protected

    //protected: members can be accessed from derived class, otherwise private

    //OOP
    //object, class, inheritance, polymorphism, encapsulation, abstraction

    //difference between while and do-while
    //while verifies the condition then iterates the loop,
    //do-while first iterates body once then checks the condition

    //what is a constructor?
    //member function that is invoked whenever object is created
    //2 types, default constructor and parameterized constructor


    //which operator cannot be overloaded?
    // ?: is no overloadable

    //write a program to find a factorial of a number

    int n;

    int fact = 1;

    cout << "enter a positive integer:";
    cin >> n;

    if(n < 0)
    {
        cout << "Error" << endl;
    }
    else
    { 
        
        for(int i=1;i<=n;i++)
        {
            fact *= i;
        }
        cout << "factorial of " << n << " = " << fact << endl;
    }


    //operator overloading is a mechanism in which a speacial meaning is 
    //given to an operator


    //we  can compile a program without a main function but we cannot run or execute
    //the program since main function is the entry point


    //call by value, changes inside the function will not change the actual val
    //call by reference is changes the actual


    //what is inline function?
    //compiler replaces the function as function at compile time

    // scope resolution operator ::

    //size of int data type: 4bytes

    //differences between new and malloc
    //new is and operator, malloc is function
    //it calls the constructor, does not call the constructor
    //there is no need to specify memory, have to specify the memory
    //can be overloaded, cannot be overloaded 


    //find the frequency of the number within a number

    int num = 1332422523;
    int k = 2;

    int c =0;
    while(num>0)
    {
        if(num%10 == k)//mod 10 of a number gives you the last digit of the num
        {
            c++;
        }
        num = num / 10;
    }

    cout << c << endl;


    //write a program to check if a number is palindrome
    int nn, numm, digit, rev =0;

    cout << "enter a positive number to check it is palindrome" << endl;
    cin >> numm;

    nn = numm;


    do{
        digit = numm % 10;
        rev = (rev * 10) + digit;
        numm = numm / 10;
    }
    while ( numm != 0);

    cout << "reverse of the number is: " << rev << endl;

    if(nn==rev) cout << "YES it is a palindrome" << endl;
    else cout << "NO it is not" << endl;


    //what is a friend function?
    //can access all members of the class
    //declared inside the class

    //what is copy constructor?
    //is a member function that initializes an object using another object within the same class
    //default and user defined

    //how does strings are stored in memory? contigiously
    //string objects have dynamic size

    test3();


    return 0;
}


//can we access the piece of memory outside of its current scope?
 int * ptrgen()
 {
    int i = 1;
    return &i;
 }

 void test()
 {
    //there will be no problem, it should print 1 and 2 but it is not
    //a guarantee.. you dont know what is going to happen to that memory
    int *p = ptrgen();
    cout << *p << endl;
    *p = 2;
    cout << *p << endl;
 }


//what is delete keyword do?

//read access violation??,  it is returning some random address
//security problems
void test2()
{
    int *i = new int; //in the heap
    *i = 100;
    delete(i);

    cout <<"asjhdlkashdlk " << *i << endl;
}


//size of struct is equal to elements's size?
struct s1
{
    char a; //1 byte
    short b; //2 bytes
    //1 byte of padding
    int c; //4 bytes
};
//total 7 bytes???

struct s2
{
    char a;
    char b;
    //2byte of padding here
    int c;
    short d;
    //2byte of padding here
};
//total 8 bytes????

void test3()
{
    s1 s;
    s2 a;

    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;

    //sizes are 8, 12 because of padding to the memory. 4 bytes of chunks

}


//what is meant by ifndef and define keywords?
//include guards, prevent the compiler to include any unnnecessary files or recursively adding

//what is the difference between NULL and NULL_pointer keyword?
//null pointer has it's own type, compiler knows that it is not zero, 

// You have a string with multiple ‘(‘ and ‘)’ and you want to check if the string is valid according to the following
// criteria:
// - Check that every open has a close parenthesis
// - Check that a close parenthesis does not come first
// Note: the string contains only parenthesis

// ((())) OK
// )((() NOT OK
// ()) NOT OK
// ()()() OK
// (()()) OK
// ())( NOT OK

// ()
bool check(std::string str)
{
    stack<char> st;
    char ch;
    
    for(int i=0; i<str.length();i++){
        st.push(str[i]); // )
        
        switch(str[i]){
            
            case '(':
            
                ch = st.top(); // (
                st.pop();
                
                if(ch != '('){
                    return false;
                }
            break;
            case ')':
                ch = st.top();
                st.pop();
                if(ch != ')')
                {
                    return false;
                }
            break;
            
        }
    }
    
    
    return true;
}
