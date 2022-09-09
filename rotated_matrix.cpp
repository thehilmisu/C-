#include <iostream>
#include <vector>
using namespace std;


const int MATRIX_SIZE = 5;

void initMatrix(int m[MATRIX_SIZE][MATRIX_SIZE])
{
    int count = 0;

    for(int rows=0;rows<MATRIX_SIZE;rows++)
    {
        for(int columns=0;columns<MATRIX_SIZE;columns++)
        {
            m[rows][columns] = count++; 
        }
    }
}

void printMatrix(int m[MATRIX_SIZE][MATRIX_SIZE])
{
       
    for(int rows=0;rows<MATRIX_SIZE;rows++)
    {
        for(int columns=0;columns<MATRIX_SIZE;columns++)
        {
            cout << m[rows][columns] ;
            if(m[rows][columns] < 10){
                cout << "        ";
            }else if(m[rows][columns] < 100){
                cout << "       ";
            }else{ cout << "     ";}
        }
        cout << endl;
    }
}

void Swap( int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;

}

void rotateBy90CounterClockwise(int m[MATRIX_SIZE][MATRIX_SIZE])
{

    int last = MATRIX_SIZE - 1;
    int level = 0; //level is 0 for both 2x2 and 3x3, 1 for 4x4 ....
    int totNumOfLevels = MATRIX_SIZE / 2;

    while(level < totNumOfLevels){


        for (int i = last; i > level; i--)
        {
            Swap(m[level][i], m[last - i + level][level]);
            Swap(m[level][i], m[last][last - i + level]);
            Swap(m[level][i], m[i][last]);
        }

        ++level;
        --last;
    }

}

void rotateBy90Clockwise(int m[MATRIX_SIZE][MATRIX_SIZE] ) //clock wise
{

    int last = MATRIX_SIZE - 1;
    int level = 0; //level is 0 for both 2x2 and 3x3, 1 for 4x4
    int totNumOfLevels = MATRIX_SIZE / 2;

    while(level < totNumOfLevels){


        for(int i=level;i<last;i++)
        {
            Swap(m[level][i],m[i][last]);
            Swap(m[level][i],m[last][last-i+level]);
            Swap(m[level][i],m[last-i + level][level]);            
        }

        ++level;
        --last;
    }

}

int main()
{

    int m[MATRIX_SIZE][MATRIX_SIZE];

    initMatrix(m);

    cout << "original matrix" << endl;
    cout << endl;

    printMatrix(m);

    cout << endl;
    cout << "rotated 90 clockwise matrix" << endl;
    cout << endl;

    rotateBy90Clockwise(m);


    printMatrix(m);

    cout << endl;
    cout << "rotated 90 counter clockwise matrix" << endl;
    cout << endl;
    
    rotateBy90CounterClockwise(m);
    rotateBy90CounterClockwise(m);

    printMatrix(m);





    return 0;
}