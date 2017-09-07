#include <vector>

using namespace std;

/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1, 2, 3] have the following permutations :

[
[1, 2, 3],
[1, 3, 2],
[2, 1, 3],
[2, 3, 1],
[3, 1, 2],
[3, 2, 1]
]
*/

class Solution {
private:
	vector<vector<int>> L;
	int level = 0;
	vector<int> out;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> visited(nums.size(),0);
		permuteDFS(nums, level, out, visited, L);
		return L;
	}

	void permuteDFS(vector<int>& nums, int level, vector<int>& out, vector<int>& visited, vector<vector<int>>& L){
		if (level == nums.size()){
			L.push_back(out);
		}
		else{
			for (int i = 0; i < nums.size();i++){
				if (visited[i] == 0){
					visited[i] = 1;
					out.push_back(nums[i]);
					permuteDFS(nums, level+1, out, visited, L);
					out.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
};