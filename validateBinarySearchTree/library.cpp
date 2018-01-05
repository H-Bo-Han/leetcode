#include "library.h"

#include <iostream>

using namespace std;

int main(){
    TreeNode *T;
    Solution so = Solution();
    so.createTree(T);
    bool res = so.validateBinarySearchTree(T);
    cout<<res<<endl;
    return 0;
}