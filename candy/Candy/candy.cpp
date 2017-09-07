#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
*There are N children standing in a line. Each child is assigned a rating value.
*You are giving candies to these children subjected to the following requirements:
*Each child must have at least one candy.
*Children with a higher rating get more candies than their neighbors.
*What is the minimum candies you must give?
*/

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.empty()){
			return 0;
		}

		vector<int> container;
		container.push_back(1);
		
		for (int i = 1; i < ratings.size();i++){
			if (ratings[i] > ratings[i-1]){
				container.push_back(container[i - 1] + 1);
			}
			else{
				container.push_back(1);
			}
		}
		
		int res = container[ratings.size()-1];
		
		for (int i = ratings.size() - 2; i >= 0; i--){
			int num = 1;
			if (ratings[i] > ratings[i + 1]){
				num = container[i + 1] + 1;
			}
			res += max(num, container[i]);
			*(container.begin() + i) = num;
		}
		
		return res;
	}
};

int main(){
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(2);
	Solution *candy = new Solution();
	int ans = candy->candy(vec);
	cout << ans;
	return 0;
}
