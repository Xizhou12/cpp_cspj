#include <bits/stdc++.h>
#
using namespace std;
int N[105] = {0};
struct TreeNode{
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

TreeNode* check_children(TreeNode* node){
    /*
              4
        2           1
     6  7  8      3  5
    int N[9]

    */
    // this function returns the child node with the most children
    int children_cnt = node->children.size();
    int max_children_cnt = children_cnt;
    TreeNode* node_max = node;
    TreeNode* child_node_max;
    for(int i = 0; i < children_cnt; i++){
        child_node_max = check_children(node->children[i]);
        if ( child_node_max->children.size() > max_children_cnt){
            max_children_cnt = child_node_max->children.size();
            node_max = child_node_max;
        }
    }
    return node_max;
}

int main(){
    int n,m;
    int parent,child;
    cin >> n >> m;
    TreeNode* root = NULL;
    TreeNode* node_max = NULL;
    TreeNode* NODE[105] = {NULL};
    while(m--){
        cin >> parent >> child;
        if(NODE[parent] == NULL){
            NODE[parent] = new TreeNode(parent);
        }
        if(NODE[child] == NULL){
            NODE[child] = new TreeNode(child);
        }
        NODE[parent]->children.push_back(NODE[child]);
        N[child] = 1;
        if(N[parent] == 0){
            root = NODE[parent];
        }
    }
    cout << root -> val << endl;
    node_max = check_children(root);
    cout << node_max -> val << endl;
    for(int i = 0; i < node_max->children.size(); i++){
        cout << node_max->children[i]->val << " ";
    }


}