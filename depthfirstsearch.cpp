#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> Vec;
vector<bool> visited;

void dfs_r(int s){
    visited[s] = true;
    cout << s << " ";
    for(int i=0;i<Vec[s].size();++i){
        if(visited[Vec[s][i]] == false)
            dfs_r(Vec[s][i]);
    }
}

//in dfs we use stack, you go depth
void dfs(const vector<vector<int>>& Vec, int s){
    std::stack<int> Stk;
    visited[s]=true;
    while(!Stk.empty()){
        int node = Stk.top();
        Stk.pop();

        cout << "visited: " << node << " ";
        for(int i=0;i<Vec[node].size();++i){
            if(!visited[Vec[node][i]]){
                Stk.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
            }
        }
    }

}

void initialize(){
    for(int i=0;i<visited.size();++i)
        visited[i] = false;

}

//in bfs we use queue, you go breaded (like horizontally, levelwise)
// like broadcasting in network, finding all nodes within one connected component
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
  int dx[] = {-2, -1,  1,  2, -2, -1, 1, 2};
  int dy[] = {-1, -2, -2, -1,  1,  2, 2, 1};

  // BFS queue
  queue<Square> q;

  Square s(startX,startY,0);  
  q.push(s);

  int x, y;
  bool visit[N + 1][N + 1];

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

    while (!q.empty()) {
      s = q.front();
      q.pop();
      
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
            cout << "x:" << x << " y:" << y << " movecount:" << s.moveCount<< endl;
            q.push(temp);
          }
        }
          
      }
    
  }

  return -1;
}

int main(){

    int res = minMoves(8,0,0,8,5);

    cout << res << endl;

    //storing undirected and directed graph
    // int nodes, edges, x, y;
    // cin >> nodes;
    // cin >> edges;

    // vector<vector<int>> Vec;
    // vector<bool> visited;
    // Vec.resize(nodes + 1);
    // visited.resize(nodes + 1);

    // for(int i=0;i<edges;++i){
    //     cin >> x >> y;
    //     Vec[x].push_back(y);
    //     Vec[y].push_back(x); //without this line, it will be directed graph
    // }


    //storing undirected and directed weighted graph
    // int nodes, edges, x, y, w;
    // cin >> nodes;
    // cin >> edges;

    // vector<vector<std::pair<int,int>>> Vec;
    // vector<bool> visited;
    // Vec.resize(nodes + 1);
    // visited.resize(nodes + 1);

    // for(int i=0;i<edges;++i){
    //     cin >> x >> y;
    //     Vec[x].push_back(make_pair(y,w));
    //     Vec[y].push_back(make_pair(x,w)); //without this line, it will be directed graph
    // }

    //storing tree
    // struct Node
    // {
    //   int edge;
    //   int weight;
    // };
    
    // int nodes, edges, x, y, w;
    // cin >> nodes;
    // cin >> edges;

    // vector<vector<Node>> Vec;
    // vector<bool> visited;
    // Vec.resize(nodes + 1);
    // visited.resize(nodes + 1);

    // for(int i=0;i<edges;++i){
    //     cin >> x >> y;
    //     Node node;
    //     node.edge = y;
    //     node.weight = w;
    //     Vec[x].push_back(node);
    //     node.edge = x;
    //     Vec[y].push_back(node); //without this line, it will be directed graph
    // }

    // initialize();

    // //dfs_r(1);
    // dfs(Vec,1);

    return 0;
}