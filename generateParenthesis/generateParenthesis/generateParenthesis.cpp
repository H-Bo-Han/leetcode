#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> vec;
		generate(n, n, "", vec);
		return vec;
	}

	void generate(int left, int right, string s, vector<string> &vec){
		if (left<right)
		{
			return;
		}
		if (left==0 && right==0)
		{
			vec.push_back(s);
		}
		if (left>0)
		{
			s = s + "(";
			generate(left-1, right, s, vec);
		}
		if (right>0 && left<right)
		{
			s = s + ")";
			generate(left, right-1, s, vec);
		}
	}
};