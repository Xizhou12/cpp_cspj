#include <bits/stdc++.h>
//http://ybt.ssoier.cn:8088/problem_show.php?pid=1336 1336������3-1���������ͺ���
/*
             4
        2         1  
     6  7  8    3  5
*/
using namespace std;
int N[105] = {0};
struct TreeNode{
    int val;
    vector<TreeNode*> children; // ���� ��Ϊ�ⲻ��һ�Ŷ����� ������Ҫ��һ���������� �������˶�̬����
    // ���ﹹ�캯����Ҫ���� �����ҽ���һ��TreeNode��ֻ��Ҫһ������ x val(x)��ָ��x��ֵ��val Ȼ��������Ž��� �Ͳ���Ҫ���ó�ʼ��children ����һ���ڵ���
    TreeNode(int x) : val(x) {} 
};
/*
    ȫ�ֱ���
*/
TreeNode* NODE[105] = {NULL};
int cnt = 0; // ������¼��ǰ���Ľڵ�ĺ�������
// ���и��ӵ��������ⶼ���õݹ�����
/*  ���еĵݹ�����˼����������
    1. �ݹ������������ʲô һ��ȷ����Ҫ��Ҫ�ڵݹ�Ĳ���Ҳͳһ
    2. �ݹ�ʲôʱ����� ͨ�����е����ĵݹ鶼����Ҷ�ӽڵ���߽ڵ�Ϊ�գ�NULL)���������Ե�
    3. �ݹ���α��һ����С������ ������������ ��Զ��ͨ���Ե�ǰ���ڵ�ĺ��ӽڵ���еݹ�
*/
TreeNode* max_children(TreeNode* node){ // ���뵱ǰ�ڵ� ���-����ǰ�ڵ㣨����ӵ�к������������Ǹ��ڵ�
    if(node == NULL){
        // ��������
        return node;
    }
    TreeNode* node_max = node; // ����� �ڶԺ��ӽڵ�ݹ�ǰ �͵��ڵ�ǰ�ڵ��Լ� ��Ϊ���Լ�Ҳ�п���ӵ�����ĺ��ӽڵ�
    for(int i = 0; i < node->children.size(); i++){
        TreeNode* child = node->children[i];
        TreeNode* t = max_children(child);
        if (cnt < t->children.size()){ // �Ƚ�
            cnt = t->children.size();
            node_max = t; // �滻���ֵΪӵ�и����������Ľڵ�
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
            ������ ����Ѱ�ҵ����ڵ�
            ����ע��ֻ�г����µ�parent childֵ����Ҫ�����µĽڵ�
            ����ֻ��Ҫ�������ӹ�ϵ�Ϳ����� ������һ��ȫ�����������Ѿ��������Ľڵ��Է���֮��ȡ������
        */
        if( NODE[parent] == NULL){
            TreeNode* x = new TreeNode(parent);
            NODE[parent] = x;
        }
        if (NODE[child] == NULL){
            NODE[child] = new TreeNode(child);
        }
        NODE[parent]->children.push_back(NODE[child]);// �������ӹ�ϵ
        
        // Ѱ�Ҹ��ڵ�
        N[child] = 1;
        if (N[parent] == 0){
            root = NODE[parent];
        }
    }

    //1. ��ӡ���ڵ�
    cout << root->val << endl;
    //2. ��ӡӵ����ຢ�ӽڵ�Ľڵ�
    cnt = root->children.size();
    TreeNode* node_max = max_children(root);
    cout << node_max->val << endl;
    //3. ��ӡӵ����ຢ�ӽڵ�Ľڵ�ĺ��ӽڵ�
    for(int i = 0; i < node_max->children.size(); i++){
        cout << node_max->children[i]->val << " ";
    }
}