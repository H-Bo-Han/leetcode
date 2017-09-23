#include <vector>
#include <iostream>
using namespace std;


/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty()){
			return 0;
		}
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int cnt = 0;
		//vector<vector<int>> obstacleGrid_bk;
		vector<vector<int>> obstacleGrid_bk(obstacleGrid);
		/*for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (obstacleGrid[i][j] == 0){
					obstacleGrid_bk[i][j] = 1;
				}
				else{
					obstacleGrid_bk[i][j] = 0;
				}
			}
		}*/

		if (obstacleGrid[0][0]==1){
			return 0;
		}

		obstacleGrid_bk[0][0] = 1;
		for (int i = 1; i < m; ++i){
			if (obstacleGrid[i][0]==1){
				obstacleGrid_bk[i][0] = 0;
			}
			else{
				obstacleGrid_bk[i][0] = obstacleGrid_bk[i - 1][0];
			}
		}

		for (int j = 1; j < n; ++j){
			if (obstacleGrid[0][j]==1){
				obstacleGrid_bk[0][j] = 0;
			}
			else{
				obstacleGrid_bk[0][j] = obstacleGrid_bk[0][j - 1];
			}
		}
		
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (obstacleGrid[i][j]==1){
					obstacleGrid_bk[i][j] = 0;
				}
				else{
					obstacleGrid_bk[i][j] = obstacleGrid_bk[i - 1][j] + obstacleGrid_bk[i][j - 1];
				}
			}
		}
		return obstacleGrid_bk[m-1][n-1];
	}
};

void main(){
	int a[] = { 0, 0, 0, 0 };
	int b[] = { 0, 1, 0, 0 };
	int c[] = { 1, 0, 0, 0 };
	vector<int> p(a, a + 4);
	vector<int> q(b, b + 4);
	vector<int> r(c, c + 4);
	vector<vector<int>> o;
	o.push_back(p);
	o.push_back(q);
	o.push_back(r);
	Solution *obj = new Solution;
	cout << obj->uniquePathsWithObstacles(o) << endl;
}