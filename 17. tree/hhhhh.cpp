#include <bits/stdc++.h>

using namespace std;


int dfs(int s, int m){
    // 这个函数要解决的问题是，将x个不同苹果放到y个相同盘子里，有多少种方法 且不会有空盘子
    // 1个苹果 || 1个盘子 || 苹果的数量== 盘子的数量 return 1种方案
    // 1000个苹果 500 个盘子 999个苹果放入500个盘子 999个苹果放入499个盘子
    1*dfs(s-1,m-1)+dfs(s-1,m)*m;
    // 1.放最后一个苹果的时候 还有一个空盘子的情况：将s-1个不同苹果放到m-1个相同盘子里方案数 * 将1个苹果放进1个盘子的方法（==1）
    // 2.放最后一个苹果的时候 没有空盘子的情况：将s-1个不同苹果放到m个相同盘子里方案数 * 将1个苹果放进m个盘子的方法（==m）
}

// dfs(1,m) 一个苹果放入 m个盘子里几种方案 m-1个盘子
// 1 10 



10 5
dfs(9, 4) = 方法数
第一件事情：将9个苹果放入4个盘子里 
第二件事情：将1个苹果放入1个盘子里 

(7 3) * (3 2)