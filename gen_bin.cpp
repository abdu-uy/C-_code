#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct treenode{
    int val;
    treenode *left;
    treenode *right;
    treenode (int x): val(x),left(NULL),right(NULL){};
};

//create tree list
treenode* listCreateTree (vector<int> treeList,int ptr){
    
    if (ptr > treeList.size()-1 || treeList[ptr] == 0)//当作空点
        return NULL;
    treenode* node;
    node = (treenode*)malloc(sizeof(treenode));
    node->val = treeList[ptr];
    node->left = listCreateTree(treeList,2*ptr+1);
    node->right = listCreateTree(treeList,2*ptr+2);
    return node;
}   

//preordef traversal
void preOrderTravelsal (treenode * root){
    if (root == NULL)
        return ;

    printf("%s",root->val);
    preOrderTravelsal(root->left);
    preOrderTravelsal(root->right);
}

//dfs_search
vector<int> dfs(treenode* root, vector<int>& result){
    if (root == NULL)
        return result;
    result.push_back(root->val);
    dfs(root->left,result);
    dfs(root->right, result);
}

vector<int> dfsTraversal(treenode* root){
    vector<int> result = {};
    dfs(root,result);
    return result;
}

