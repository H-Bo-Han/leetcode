#include<iostream>
#include <vector>
#include <list>
using namespace std;

/*
This problem is given by the google:
You are given an Array of numbers and they are unsorted/random order. 
You are supposed to find the longest sequence of consecutive numbers in the array. 
Note the sequence need not be in sorted order within the array. 
Here is an example :
	Input :
		A[] = {10,21,45,22,7,2,67,19,13,45,12,11,18,16,17,100,201,20,101}
	Output is :
		{16,17,18,19,20,21,22}
The solution needs to be of O(n) complexity.
*/
class Solution{
public:
	int LongestSubstring(vector<int>&nums){
		int max_length = 0;
		int start_val = 0;
		int end_val = 0;
		list<int> nums_list(nums.begin(), nums.end());
		while (nums_list.size() > 0){
			int it = nums_list.front();
			nums_list.pop_front();
			int start = it, end = it;
			int start_cnt = 1, end_cnt = 1;
			vector<int> start_ans;
			vector<int> end_ans;
			FindStart(nums_list, start, start_cnt, start_ans);
			FindEnd(nums_list, end, end_cnt, end_ans);
			int len_seq = start_ans[1] + end_ans[1] - 1;
			if (len_seq > max_length){
				max_length = len_seq;
				start_val = start_ans[0];
				end_val = end_ans[0];
			}
		}
		cout << "The max value: "<<start_val << endl;
		cout << "The min value: "<<end_val << endl;
		cout << "So the longest sequence of consecutive numbers is " << end_val << "..." << start_val << endl;
		return max_length;
	}

	void FindStart(list<int>&nums_list, int start, int start_cnt, vector<int>&start_ans){
		int old_size = nums_list.size();
		nums_list.remove(start + 1);
		int new_size = nums_list.size();
		if (old_size != new_size){
			start += 1;
			start_cnt += 1;
			FindStart(nums_list, start, start_cnt, start_ans);
		}
		else{
			start_ans.push_back(start);
			start_ans.push_back(start_cnt);
		}
		return;
	}

	void FindEnd(list<int>&nums_list, int end, int end_cnt, vector<int>&end_ans){
		int old_size = nums_list.size();
		nums_list.remove(end - 1);
		int new_size = nums_list.size();
		if (old_size != new_size){
			end -= 1;
			end_cnt += 1;
			FindEnd(nums_list, end, end_cnt, end_ans);
		}
		else{
			end_ans.push_back(end);
			end_ans.push_back(end_cnt);
		}
		return;
	}
	
};

void main(){
	int A[] = { 10, 21, 45, 22, 7, 2, 67, 19, 13, 45, 12, 11, 18, 16, 17, 100, 201, 20, 101 };
	vector<int> nums(A, A+19);
	Solution *obj = new Solution;
	int ans = obj->LongestSubstring(nums);
	cout << "The longest length: "<<ans << endl;
}