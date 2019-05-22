#include <iostream>
#include "Solution.h"

using namespace std;
/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
 */
int main() {
    int n=3;
    Solution *obj=new Solution;
    int ans=obj->climbStairs(n);
    cout<< ans <<endl;
    return 0;
}