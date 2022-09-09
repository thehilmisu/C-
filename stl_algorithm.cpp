#include <stdio.h>
#include <iostream>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define INT_MAX 215454654654

bool f(int x, int y)
{
    return x > y;
}

void PowerOfSTLDemo()
{
    set< pair<int, int>> S;

    S.insert({401,450});
    S.insert({10,20});
    S.insert({2,3});
    S.insert({30,400});


    int point = 50;

    auto it = S.upper_bound({point, INT_MAX});
    if(it == S.begin())
    {
        cout << "NO" << endl;
        return;
    }
    it--;
    pair<int, int> current = *it;

    if(current.first <= point && point <= current.second){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main()
{

    vector<int> A = {11,2,3,14};

    cout << A[1] << endl;

    sort(A.begin(), A.end()); //O(NlogN)

    //2,3,11,14

    //O(logN)
    bool present = binary_search(A.begin(), A.end(), 3);//true
    present = binary_search(A.begin(), A.end(), 4);//false

    A.push_back(100);

    present = binary_search(A.begin(), A.end(), 100);//true

    //2,3,11,14,100

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    
    //2,3,11,14,100,100,100,100,100
    A.push_back(123);


    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // <= logN
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // > logN

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; //5 O(1), number of times 100 occurring in the vector


    sort(A.begin(), A.end(), f);
    vector<int>::iterator it3;

    for(it3 = A.begin(); it3 != A.end(); it3++)
    {
        cout << *it3 << " ";
    }
    cout << endl;

    for(int x : A)
    {
        x++;
        cout << x << " ";
    }
    cout << endl;

    for(int &x : A)
    {
        x++;
        cout << x << " ";
    }
    cout << endl;


    ////////////////////////////////////////////////////////


    set<int> S; //internally inserting in ascending order, each operation is logN

    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);


    for(int x : S)
        cout << x << " ";

    cout << endl;

    //-10 -1 1 2
    auto it5 = S.find(-1);//it will now pointing the -1

    if(it5 == S.end())
    {
        cout << "not present";
    }
    else{
        cout << "present : " << *it5 << endl;
    }

    auto it6 = S.lower_bound(-1);//will give the iterator <= to -1


    auto it7 =  S.upper_bound(2);//does not exist so it returns S.end();
    /////////////////////////////////////

    map<int, int> M; // in logN time you can map something to something
    // .find(key) and erase(key) also logN

    M[1] = 100;
    M[2] = -1;
    M[3] = 200;
    M[100000232] = 1;

    map<char, int> cnt;

    string x = "rachit jain";

    for(char c : x)
    {
        cnt[c]++; //how many times character occures in a string 
    }

    cout << cnt['a'] << " " << cnt['z'] << endl;


    ///////////////////////////////////////////////////////////

    map<char, int> MM; //add logN
    unordered_map<char, int> U;//add O(1)

    string s = "Rachit Jain";

    for( char c : s) MM[c]++; // O(NlogN) N is size of the string

    for( char c : s) U[c]++; // O(N)     


    return 1;
}

//write function that prints YES if we can divide the array in 2 parts
//prints NO if we cannot divide
int solution()
{
    int n;

    cin >> n;
    vector<int> A(n + 1, 0);

    long long S = 0;

    

    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        S += A[i];
    }

    if(S & 1)
    {
        cout << "NO" << endl;
        return 0;
    }


    map<long long, int> first, second; // use unordered_map to have better time

    first[A[0]] = 1;

    for(int i =1; i<n; i++) second[A[i]]++;

    int sdash = 0;
    for(int i = 0; i < n ; i++)
    {
        sdash += A[i];
        if(sdash == S / 2)
        {
            cout << "YES" << endl;
            return 0;
        }
        if(sdash < S / 2)
        {
            long long x = S / 2 - sdash;
            //delete element from second half and insert into first half
            if(second[x] > 0)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        else
        {
            long long y = sdash - S / 2;
            if(first[y] > 0)
            {
                cout << "YES" << endl;
                return 0;
            }
        }

        first[A[i+1]]++;
        second[A[i+1]]--;
    }

    cout << "NO" << endl;
    return -1;

}