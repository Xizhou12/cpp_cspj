#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode{ // 不是一颗 二叉树
    int val;
    std::vector<TreeNode*> direct_related_blood; // 数组
    // 成员
    TreeNode(int v){
        val = v;
    }
};
TreeNode n;
n.val == p->val
TreeNode *p;


TreeNode * construct_family_tree(){
    TreeNode* you = new TreeNode(0);
    TreeNode* dad = new TreeNode(1);
    TreeNode* mom = new TreeNode(2);
    TreeNode* bro = new TreeNode(3);
    TreeNode* sis = new TreeNode(4);
    TreeNode* uncle = new TreeNode(5);
    TreeNode* aunt = new TreeNode(6);
    TreeNode* granddad = new TreeNode(7); // 爷爷
    TreeNode* grandma = new TreeNode(8);  // 外婆
    you->direct_related_blood.push_back(dad);
    you->direct_related_blood.push_back(mom);
    you->direct_related_blood.push_back(bro);
    you->direct_related_blood.push_back(sis);
    dad->direct_related_blood.push_back(uncle);
    dad->direct_related_blood.push_back(aunt);
    dad->direct_related_blood.push_back(granddad);
    mom->direct_related_blood.push_back(grandma);
    return you;
}

int main(){
    TreeNode * root = construct_family_tree(); //  创建这颗family tree
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front();
        cout << current->val << endl; // 遍历过他了
        q.pop();
        for(int i = 0; i < current->direct_related_blood.size(); i++){
            q.push(current->direct_related_blood[i]);
        }
    }
}