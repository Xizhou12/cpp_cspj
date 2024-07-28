/*
1335：【例2-4】连通块

时间限制: 1000 ms         内存限制: 65536 KB
提交数:18326    通过数: 10498
【题目描述】
一个n × m的方格图，一些格子被涂成了黑色，在方格图中被标为1，白色格子标为0。问有多少个四连通的黑色格子连通块。四连通的黑色格子连通块指的是一片由黑色格子组成的区域，其中的每个黑色格子能通过四连通的走法（上下左右），只走黑色格子，到达该联通块中的其它黑色格子。

【输入】
第一行两个整数n,m(1≤n,m≤100)，表示一个n × m的方格图。

接下来n行，每行m个整数，分别为0或1，表示这个格子是黑色还是白色。

【输出】
一行一个整数ans，表示图中有ans个黑色格子连通块。

【输入样例】
3 3

1 1 1  bfs 队列 {  }  （0，1）x[0][1] == 1 return
0 1 0
1 0 1
x[0][-1]  0 <= i ,j < 3
seen[0][0] = true

我们需要两个二维数组
int x[3][3] = {{1, 1, 1}, {0, 1, 0}, {1, 0, 1}}; // 记录大陆海洋的信息
int seen[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; // 这一个大陆我有没有来过
int res = 0; //岛屿数量
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        // 这个点我没见过 其次这个点x[i][j] == 1
        res += dfs_2(i，j); // 走完一个完整的连通块会返回 其实所有走过的格子 我会把他标记成 我走过了 seen【0】【0】 = 1 这个函数结束代表我成功走完一片岛屿
    }
}

【输出样例】
3
*/

#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <stdlib.h>
using namespace std;

int x[101][101]; // 这个用来存 它是0还是1 1是陆地 联通的陆地有多少个
int seen[101][101] = {0}; // 这个用来存这格地块有没有来过

/*
 1 1 1
 0 1 0
 1 0 1
*/
int dfs_2(int i,int j){
    if(seen[i][j] == true || x[i][j] == 0){
        return 0; // 
    }

    // 这是一块我没有来的大陆
    seen[i][j] = true; // 自动把他标记成我已经来过
    // 上下左右
    int new_i = i, new_j = j + 1; //上
    if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3 && x[new_i][new_j] == 1 && seen[new_i][new_j] == 0){
        // 上方是一个陆地
        dfs_2(new_i, new_j);
    }

    new_i = i, new_j = j-1; //下
    if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3 && x[new_i][new_j] == 1 && seen[new_i][new_j] == 0){
        // 下方是一个陆地
        dfs_2(new_i, new_j);
    }

    new_i = i+1, new_j = j; //左
    if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3 && x[new_i][new_j] == 1 && seen[new_i][new_j] == 0){
        // 左方是一个陆地
        dfs_2(new_i, new_j);
    }
    new_i = i-1, new_j = j; // 右
    if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3 && x[new_i][new_j] == 1 && seen[new_i][new_j] == 0){
        // 右方是一个陆地
        dfs_2(new_i, new_j);
    }
    return 1;
}


int main_2(){
    int n,m; // 地图的长宽
    cin >> n  >> m;
    int result = 0; // 有多少个陆地
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result += dfs_2(i,j); // 
        }
    }
    cout << result << endl;
}


int dfs(int x, int y, int n, int m, vector<vector<int>> &a, vector<vector<int>> &visited){

    if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0 || a[x][y] == 0 || visited[x][y] == 1 ){
        return 0;
    }
    visited[x][y] = 1;
    dfs(x+1, y, n, m, a, visited);
    dfs(x-1, y, n, m, a, visited);
    dfs(x, y+1, n, m, a, visited);
    dfs(x, y-1, n, m, a, visited);
    return 1;
}

int bfs_id(int x, int y, int n, int m, vector<vector<int>> &a, vector<vector<int>> &visited){
    queue<int> q;
    int id = m * x + y; // unique id 0 , 1 ,2 ,3 , 4 , 5
    q.push(id); // push to queue a unique id
    visited[x][y] = 1;
    while(!q.empty()){
        int cur = q.front(); // 
        q.pop();
        int x = cur / m;
        int y = cur % m;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto dir : directions){ 
            int x_new = x + dir[0];
            int y_new = y + dir[1];
            if(x_new >= 0 && x_new < n && y_new >= 0 && y_new < m && a[x_new][y_new] == 1 && visited[x_new][y_new] == 0){
                q.push(m * x_new + y_new);
                visited[x_new][y_new] = 1;
            }
        }
    }
    return 1;
}

int bfs(int x, int y, int n, int m, vector<vector<int>> &a, vector<vector<int>> &visited){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y)); // you can use int id = m * x + y as well, row_id = id /m, col_id = id % m;
    visited[x][y] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for(pair<int,int> p : {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)}){
            int x_new = x + p.first;
            int y_new = y + p.second;
            if(x_new >= 0 && x_new < n && y_new >= 0 && y_new < m && a[x_new][y_new] == 1 && visited[x_new][y_new] == 0){
                q.push(make_pair(x_new, y_new));
                visited[x_new][y_new] = 1;
            }
        }
    }
    return 1;
}


int main(){
    // 输入
    int n, m, res = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0)); // 记录是否访问过
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    /*
        对地图上的每一个点都进行一次bfs或者dfs操作
        无论是bfs 还是 dfs 都是对每个相连并未探索的点（包括自己） 进行探索，若探索完成以后没有其他连接点以后，返回1 代表这些点代表一个连通块
    */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (!visited[i][j] && a[i][j] == 1){
                res += bfs(i, j, n, m, a, visited);
                // res += bfs_id(i, j, n, m, a, visited);
                // res += dfs(i, j, n, m, a, visited);
            }
        }
    }
    cout << res << endl;
}