#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    /*
        树的构造
        1. 指针构造
        2. struct类型本身构造
          1
        2   3
      4 5   6 7
    */
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    inorder(a); //中序遍历
    TreeNode a_ = TreeNode(1);
    TreeNode b_ = TreeNode(2);
    TreeNode c_ = TreeNode(3);
    TreeNode d_ = TreeNode(4);
    TreeNode e_ = TreeNode(5);
    TreeNode f_ = TreeNode(6);
    TreeNode g_ = TreeNode(7);

    a_.left = &b_;
    a_.right = &c_;
    b_.left = &d_;
    b_.right = &e_;
    c_.left = &f_;
    c_.right = &g_;
    inorder(&a_); //中序遍历
    return 0;
}