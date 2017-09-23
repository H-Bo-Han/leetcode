//
// Created by lutingting on 2017/9/22.
//

#ifndef JUMPGAMEII_SOLUTION_H
#define JUMPGAMEII_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

/*List all the possibile paths could cause the time limited error!!!
 * class Solution {

public:
    int jump(vector<int>& nums) {
        if(nums.empty() || nums[0]==0 || nums.size()==1){
            return 0;
        }
        cout<<"The path is: ";
        for(int i=0; i<nums.size(); i++){
            cout<< nums[i] << " ";
        }
        cout<< endl;

        vector<int> ans;
        generate(nums, ans, 0, 0);
        auto m=min_element(begin(ans),end(ans));
        return *m;
    }

    void generate(vector<int>& nums, vector<int>& ans, int i, int cnt){
        int current = nums[i];
        if(current + i >= nums.size()-1){
            ans.push_back(cnt+1);
            return ;
        }
        else{
            cnt++;
            for(int j=1;j<=current;j++){
                generate(nums, ans, i+j, cnt);
            }

        }

    }
};*/


class Solution {

public:
    int jump(vector<int>& nums) {
        int ret=0;
        int curMax=0;
        int curRch=0;
        for(int i=0; i<nums.size();i++){
            if(curRch < i){
                ret++;
                curRch=curMax;
            }
            curMax=max(curMax, nums[i]+i);
        }
        return ret;
    }

};

#endif //JUMPGAMEII_SOLUTION_H
