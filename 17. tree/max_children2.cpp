#include <bits/stdc++.h>
//http://ybt.ssoier.cn:8088/problem_show.php?pid=1336 1336：【例3-1】找树根和孩子
/*
             4
        2         1  
     6  7  8    3  5
*/
using namespace std;
int N[105] = {0};
struct TreeNode{
    int val;
    vector<TreeNode*> children; // 孩子 因为这不是一颗二叉树 所以需要用一个数组来存 这里用了动态数组
    // 这里构造函数需要掌握 这里我建立一个TreeNode就只需要一个参数 x val(x)是指把x赋值给val 然后跟大括号结束 就不需要不用初始化children 建立一个节点了
    TreeNode(int x) : val(x) {} 
};
/*
    全局变量
*/
TreeNode* NODE[105] = {NULL};
int cnt = 0; // 用来记录当前最大的节点的孩子数量
// 所有复杂的树的问题都是用递归做的
/*  所有的递归问题思考以下问题
    1. 递归的输入和输出是什么 一旦确定了要需要在递归的部分也统一
    2. 递归什么时候结束 通常所有的树的递归都是在叶子节点或者节点为空（NULL)结束都可以的
    3. 递归如何变成一个更小的问题 在树的问题中 永远是通过对当前根节点的孩子节点进行递归
*/
TreeNode* max_children(TreeNode* node){ // 输入当前节点 输出-》当前节点（树）拥有孩子数量最大的那个节点
    if(node == NULL){
        // 结束条件
        return node;
    }
    TreeNode* node_max = node; // 输出： 在对孩子节点递归前 就等于当前节点自己 因为它自己也有可能拥有最多的孩子节点
    for(int i = 0; i < node->children.size(); i++){
        TreeNode* child = node->children[i];
        TreeNode* t = max_children(child);
        if (cnt < t->children.size()){ // 比较
            cnt = t->children.size();
            node_max = t; // 替换输出值为拥有更大孩子数量的节点
        }
    }
    return node_max;
}


int main(){
    int n,m;
    TreeNode* root = NULL; //
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int parent, child; // parent child
        cin >> parent >> child;
        /*
            构建树 并且寻找到跟节点
            这里注意只有出现新的parent child值才需要构建新的节点
            否则只需要建立父子关系就可以了 可以用一个全局数组来存已经创建过的节点以方便之后取出来用
        */
        if( NODE[parent] == NULL){
            TreeNode* x = new TreeNode(parent);
            NODE[parent] = x;
        }
        if (NODE[child] == NULL){
            NODE[child] = new TreeNode(child);
        }
        NODE[parent]->children.push_back(NODE[child]);// 建立父子关系
        
        // 寻找根节点
        N[child] = 1;
        if (N[parent] == 0){
            root = NODE[parent];
        }
    }

    //1. 打印根节点
    cout << root->val << endl;
    //2. 打印拥有最多孩子节点的节点
    cnt = root->children.size();
    TreeNode* node_max = max_children(root);
    cout << node_max->val << endl;
    //3. 打印拥有最多孩子节点的节点的孩子节点
    for(int i = 0; i < node_max->children.size(); i++){
        cout << node_max->children[i]->val << " ";
    }
}