#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
 (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
 */

int main() {
    Solution *p = new Solution;
    int arr[]={2,9,6,5,7,0,7,2,7,9,3,2,2,5,7,8,1,6,6,6,3,5,2,2,6,3};
    vector<int> nums(arr, arr+26);
    cout<< p->jump(nums) <<endl;
}