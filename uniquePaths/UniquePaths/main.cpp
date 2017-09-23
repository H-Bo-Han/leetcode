#include <iostream>
#include <vector>
using namespace std;
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
		/*
		final point:[m-1, n-1]
		First I only think out the backtrack method:
			Node: A[l][r]
			if(l=m-1 && r=n-1){
				cnt += 1;
				return;
			}
			uniquePaths(l+1, r);
			uniquePaths(l, r+1);
		But it will cause the time exceeds problem.
		Give the code in the comment parts.
		I really don't understand the dynamic programming VS backtrack method.
		For the dynamic programming, give the recurrence formula:
		A[I][J]=A[I-1][J]+A[I][J-1]£»
		The final node is A[m-1][n-1]
		*/
		vector<vector<int>> v(m, vector<int>(n, 1));
		for (int i = 1; i<m; ++i){
			for (int j = 1; j<n; ++j){
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}

	
};

void main(){
	Solution *obj = new Solution;
	cout << obj->uniquePaths(21,13) << endl;
	delete obj;
	Solution obj1 = Solution();
	cout << obj1.uniquePaths(60, 16) << endl;
	return;
}

/*
Backtrack method:
class Solution {
private:
	int cnt=0;
public:
	int uniquePaths(int m, int n) {
		int l = 0, r = 0;
		walk(l, r, cnt, m, n);
		return cnt;
	}

	void walk(int l, int r, int& cnt, int m, int n){
		if (l == m - 1 && r == n - 1){
			cnt += 1;
			return;
		}
		if (l < m - 1){
			walk(l + 1, r, cnt, m, n);
		}
		if (r < n - 1){
			walk(l, r + 1, cnt, m, n);
		}
		return;
	}
};
*/