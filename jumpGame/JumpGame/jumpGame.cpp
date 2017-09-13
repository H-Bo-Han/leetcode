#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
Given an array of non - negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example :
A = [2, 3, 1, 1, 4], return true.

A = [3, 2, 1, 0, 4], return false.
*/

class Solution {
	
public:
	bool canJump(vector<int>& nums) {
		//greedy algorithm
		if (nums.empty()){
			return false;
		}
		int reach = 0;//reach the max position
		for (int i = 0; i<=reach && i < nums.size()-1;i++){
			reach = max(i+nums[i], reach);
		}
		if (reach < nums.size()-1){
			return false;
		}
		return true;
	}
};

void main(){
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(3);
	/*nums.push_back(0);
	nums.push_back(4);*/
	Solution *s = new Solution;
	bool ans = s->canJump(nums);
	cout << ans << endl;
}

