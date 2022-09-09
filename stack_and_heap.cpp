#include <stdio.h>
#include <vector>


struct Vector3
{
    float x, y, z;

    Vector3() : x(10), y(10), z(10) {}
};

int main()
{
    //stack and heap are two different parts of memeory 
    //we have actually on the ram

    //memory allocation is different

    int val = 5; //it is allocated on the stack
    int* hvalue = new int; //on heap
    *hvalue = 5;


    int array[5]; //allocated on the stack

    int *harray = new int[5];//allocated on heap


    Vector3 vector; //stack

    Vector3* hvector = new Vector3();//heap

   

    //manually free the memory for heap, 
    //stack is automatically deletes if out of scope
    delete hvalue;
    delete[] harray;
    delete hvector;


    //new keyword: calling malloc to allocate memory from heap
    //malloc is a heavy function...

    //allocation in heap is expensive, stack is just one CPU instruction

    return 0;
}