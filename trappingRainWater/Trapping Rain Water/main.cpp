#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int ans(0);
		vector<int> container(0);
		//采用两次循环遍历：
		//第一次，从左向右遍历，找到每一个柱子左边的最大值，
		//第二次，从右向左遍历，找到每一个柱子右边的最大值，用min(左边最大，右边最大)-当前柱子的高度，即为当前柱子能够盛水的大小。
		int _max = 0;
		for (int i = 0; i < height.size();i++){
			container.push_back(_max);
			_max = max(_max, height[i]);
		}
		int max_ = 0;
		for (int i = height.size() - 1; i >= 0;i--){
			int decision = min(max_, container[i]);
			max_ = max(height[i], max_);
			ans += (decision-height[i])>0 ? decision-height[i] : 0;
		}
		return ans;
	}	
};