#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>


int something()
{
    return 1;
}

int main()
{
    //array. have to be contiguous, 
    //there should be no spaces between the elements in memory
    //this makes them fast access
    int a[10]; //stack, allocated compile time, 
               //deleted automatically when out of scope

    int* b = new int[10];//heap, allocated run time

    delete[] b; //it does not get deleted automatically, you should handle


    std::array<int, 10> c;

    for(auto& i : c)//initializing
    {
        i = something();
    }
    for(auto i = c.begin(); i != c.end(); ++i)//initializing
    {
        *i = something();
    }

    std::fill(c.begin(),c.end(),something());//initializing

    c = {1, 2, 3, 4, 5, 6, 7} ;//initializing


    //vectors. like an array but it can grow in terms of size
    //contigious like an array for fast indexible index. it is contigious
    //but if there is no space in memory block, it will copy all of the block to
    //more spacious block to remain contigious again






    //list. it is not contigious, when you add some element to
    //it will be go somewhere random in the memory.. adding elements
    //to front, it will be faster. removing or adding is cheaper than 
    //vector. counting size is not cheaper than the vector. we cant use 
    //[] brakets for the list. is usefull when you need to remove or 
    //add things to it but it is not usefull for reaching a specific item

    //deque, double ended queue. it is like linked list of arrays. it is like having
    //good features of vector and array. inserting something at the middle maybe overhead
    //cheap insertion on both hands, but is not as fast as vector to random access
    //taking blocks of memory in the memory.


    //set. set of unique object. sorts the objects, ascending. there is no pushback, there is insert
    //inserting took more time, since it will sort and look for the uniqueness. items will
    //be at the same block of the memory

    //unorderedset. unique object. not sorting and we will have more performance.

    //map. requires two type specifiers. key value pairs. 
    //it will sort according to key. if it is string it will be alphabetical order
    //unordered map will be not sorted.

    std::unordered_map<std::string, int> container;
    container["one"] = 1;
    container["two"] = 2;
    container["three"] = 3;
    container["four"] = 4;
    container["five"] = 5;
    container["six"] = 6;

    for(auto& i : container)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }





}