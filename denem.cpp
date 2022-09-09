#include <stdio.h>
#include <iostream>
#include <type_traits>

template< class T>
void stripConst( T arg)
{
    typename std::remove_const<T>::type new_arg;

    if(std::is_const<decltype(new_arg)>::value)
        std::cout << "ex" << std::endl;
    else    
        std::cout << "else" << std::endl;
}

class E1{
    public:
        virtual void printer() { std::cout << "e1  ";}

};

class E2 : public E1 {
    public:
        void printer() { std::cout << "e2  "; }
};

int getAge(int id)
{

    E1 e1;
    E2 e2;

    int Age = 0;

    if(id == 102)
    {
        throw(e1);
    }
    else{
        throw(e2);
    }

    return Age;
}

int getLength()
{
    return 10;
}

class Repo{

public:
    virtual int getVolume() { return 0;};
    char getType() {return 'R';};

};

class Vault: public Repo{
    virtual int getVolume() { return 150;};
    char getType() {return 'V';};
};

class Safe: public Repo{
    virtual int getVolume() { return 50;};
    char getType() {return 'S';};
};

void show(Repo* repos)
{
    std::cout << repos->getType() << repos->getVolume() << std::endl;
}


class Base{
    public:
        void func(){}
};

class Derived : public Base{
    public:
        void func() {}
};

int some()
{
    return 10;
}


   int b =1;

    int x() { b++; return b;}
    int y() { b*=3; return b-1;}
    int z() { b=b+8; return b+2;}

int main()
{


    int a = x() - y() + z();

    std::cout << a;

    // auto a1 = 5;
    // auto a2 = some();

    // decltype(a2) d4;
    // decltype(some()) d5 =5;

    // double a3 = 4.0;
    // auto &a6 = a3;

    // int r = 0;
    // int arr[5] = {2,4,6};
    // int *p = arr;


    // r = *(arr+2);
    // std::cout << r << std::endl;

    // r = *arr[2];
    // std::cout << r << std::endl;


    // r = p+2;
    // std::cout << r << std::endl;

    // r = *(arr+p);
    // std::cout << r << std::endl;

    // r = p[2];
    // std::cout << r << std::endl;


    //std::cout << a1 << " " << a2 << " " << d4 << " " << d5 << " " << a3 << " " << a6 << " " << std::endl;

    // Derived objDerived;

    // std::cout << objDerived << std::endl;

    //objDerived::func();

    //Base::Derived::func();

    //Derived::func();

    

    // Repo repos;
    // Vault v;
    // Safe s;

    // show(&repos);
    // show(&v);
    // show(&s);

    // int size = getLength();
    // char message[size];


    // int num, denum;

    // num = 10.0;
    // denum = 3.0;

    // for(char idx = 0; idx < 250; idx++)
    // {
    //     std::cout << "hell " << std::endl;
    // }

    // stripConst("Blinking");
    // stripConst(676);
    // stripConst(3.14);
    
    
    // int age;

    // for(int id=101;id<104;id++)
    // {
    //     try{
    //         age = getAge(id);
    //     }
    //     catch(E1 &a)
    //     {
    //         a.printer();
    //     }

    // }



    return 0;
}