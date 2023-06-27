// - Commits made to this branch must be relevant to this branch's work.

// - Every commit should contain good explanation of what has done.

// - Relevant codes must be committed together if the context of the work is big.

// - If your commit message is too long and hard to understand, you have done too much irrelevant work in that commit

// - It is good to have create rules about commit structure with your team. This allows you and your team to understand easily

// -----------------------------------------------------------------------------------

// - It must be self documented code which means add a comment every possible logic

// - If you write in c++ you need to use c++ and oop basics together to get efficiency in your code. 

// - Latest c++ releases must be followed and understand correctly to catch up with the latest technologies. 

// - Get along with c++ libraries to not to write unnecessary code snippets.


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER endX
 *  5. INTEGER endY
 */

class Square{
public:
  Square(int sx, int sy, int sMoveCount){x = sx;y=sy;moveCount=sMoveCount;}
  int x, y;
  int moveCount;
};

int minMoves(int N, int startX, int startY, int endX, int endY) {

  if((startX == endX) && (startY == endY))
    return -1;

  // every possible x,y values for knight
  int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
  int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

  // BFS queue
  queue<Square> q;

  Square s(startX,startY,0);  
  q.push(s);

  int x, y;
  bool visit[N + 1][N + 1];
ties.sh | bash

  // mark every cell unvisited
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      visit[i][j] = false;
    }
  }
    
   // mark starting point visited
    visit[startX][startY] = true;
    int count = 0;
  
    while (!q.empty()) {
      s = q.front();
      q.pop();
      count++;
      
      //arrived the target
      if ((s.x == endX) && (s.y == endY))
        return s.moveCount;

      // try every possible x,y values
      for (int i = 0; i < 8; i++) {
        x = s.x + dx[i];
        y = s.y + dy[i];

        if (x >= 0 && x <= N && y >= 0 && y <= N)//is inside the board
        {
          if (!visit[x][y]) {//is not visited
            visit[x][y] = true;
            Square temp(x, y, s.moveCount+1);
            q.push(temp);
          }
        }
          
      }
    
  }

  return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string startX_temp;
    getline(cin, startX_temp);

    int startX = stoi(ltrim(rtrim(startX_temp)));

    string startY_temp;
    getline(cin, startY_temp);

    int startY = stoi(ltrim(rtrim(startY_temp)));

    string endX_temp;
    getline(cin, endX_temp);

    int endX = stoi(ltrim(rtrim(endX_temp)));

    string endY_temp;
    getline(cin, endY_temp);

    int endY = stoi(ltrim(rtrim(endY_temp)));

    int result = minMoves(n, startX, startY, endX, endY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
