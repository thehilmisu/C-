#include <iostream>
using namespace std;

/* Implement Langton's ant:
 * https://en.wikipedia.org/wiki/Langton%27s_ant
 *
 * Hints: no UI, write testable code.
 */

#define  NORTH  0
#define  SOUTH  1
#define  EAST   2
#define  WEST   3

int main(){
  int size = 1000;
  
  int **board = new int*[size];
  
  for(int i=0;i<size;i++)
    board[i] = new int[size];

  int steps = 0;
  
  int dir = SOUTH;
  
  int x = size/2;
  int y = size/2;
  
  
  while(true){
   
    if(board[x][y] == 0){
     
      board[x][y] = 1;
      
      switch (dir){
       
        case NORTH:
          dir = EAST;
          x = x + 1;
          break;
        case SOUTH:
          dir = WEST;
          x = x - 1;
          break;
        case EAST:
          dir = SOUTH;
          y = y - 1;
          break;
        case WEST:
          dir = NORTH;
          y = y + 1;
          break;
      }
      
    }
    else{
      board[x][y] = 0;
      
      switch (dir){
       
        case NORTH:
          dir = WEST;
          x = x - 1;
          break;
        case SOUTH:
          dir = EAST;
          x = x + 1;
          break;
        case EAST:
          dir = NORTH;
          y = y + 1;
          break;
        case WEST:
          dir = SOUTH;
          y = y - 1;
          break;
      }
      steps++;
      
      if( (x >= size) || ( y >= size)){
          break;
      }
      else if ( (x <= 0) || (y <= 0)){
         break;
      }   
      
    }
    
  }
  
  cout << steps << ": " << x << ": " << y << ": " << dir << endl;
  
  
}