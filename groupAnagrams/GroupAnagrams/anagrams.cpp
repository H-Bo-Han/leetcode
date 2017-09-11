#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <typeinfo.h>
#include <string>
using namespace std;

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note: All inputs will be in lower-case.
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> sortMap;
		for (int i = 0; i < strs.size(); i++){
			string temp = strs[i];
			sort(strs[i].begin(), strs[i].end());
			sortMap[strs[i]].push_back(temp);
			//sortMap.insert(pair<string, string>(strs[i], temp));
		}
		for (auto s:sortMap){
			res.push_back(s.second);
		}
		return res;
	}
};

void main(){
	vector<string> T;
	vector<vector<string>> ans;
	T.push_back("eat");
	T.push_back("tea");
	T.push_back("tan");
	T.push_back("ate");
	T.push_back("nat");
	T.push_back("bat");
	Solution *obj = new Solution();
	ans = obj->groupAnagrams(T);
	for (int i = 0; i < ans.size();i++){
		printf_s("The %dth Result: \n",i+1);
		for (int j = 0; j < ans[i].size();j++){
			cout << ans[i][j] << endl;
		}
	}
}