#ifndef VALIDATEBINARYSEARCHTREE_LIBRARY_H
#define VALIDATEBINARYSEARCHTREE_LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution
{
public:
    TreeNode createTree(TreeNode* &T){
        char val;
        for(int i=0; i < 3; ++i){
            if(val=getchar() == '#'){
                T = NULL;
            }else{
                int val_int = (int)val;
                T = new TreeNode(val_int);
                createTree(T->left);
                createTree(T->right);
            }
        }
    }

    bool validateBinarySearchTree(TreeNode *root){
        if(root==NULL){
            return false;
        }
        int max = LONG_MAX;
        int min = LONG_MIN;
        vector<int> ans;
        transverTree(root,ans);
        for(int i=1; i<ans.size(); i++){
            if(ans[i-1] > ans[i]){
                return false;
            }
        }
    }

    void transverTree(TreeNode *p, vector<int>& q){
        if(p==NULL){
            return;
        }
        transverTree(p->left, q);
        q.push_back(p->val);
        transverTree(p->right, q);
    }

};

#endif