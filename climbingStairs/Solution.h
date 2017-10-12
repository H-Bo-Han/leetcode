//
// Created by lutingting on 2017/9/23.
//

#ifndef CLIMBINGSTAIRS_SOLUTION_H
#define CLIMBINGSTAIRS_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n>1){
            vector<int> dp(n+1);
            dp[0]=1;
            dp[1]=1;
            for(int i=2; i<=n; i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }else{
            return 1;
        }
    }
};


#endif //CLIMBINGSTAIRS_SOLUTION_H
