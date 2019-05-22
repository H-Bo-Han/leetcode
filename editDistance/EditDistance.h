//
// Created by lutingting on 2017/11/20.
//

#ifndef EDITDISTANCE_EDITDISTANCE_H
#define EDITDISTANCE_EDITDISTANCE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.length()+1;
        int n2=word2.length()+1;
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i=0;i<n2;i++){
            tmp.push_back(0);
        }
        for(int j=0;j<n1;j++){
            res.push_back(tmp);
        }

        for(int i=0;i<n2;i++){
            res[0][i]=i;
        }
        for(int j=0;j<n1;j++){
            res[j][0]=j;
        }

        for(int i=1;i<n1;i++){
            for(int j=1;j<n2;j++){
                int tmp_step=0;
                if(word1[i-1]==word2[j-1]){
                    tmp_step=0+res[i-1][j-1];
                }
                else{
                    tmp_step=1+res[i-1][j-1];
                }
                int tmp_step2=min(res[i-1][j]+1, res[i][j-1]+1);
                res[i][j]=min(tmp_step,tmp_step2);
            }
        }
        return res[n1-1][n2-1];

    }
};


#endif //EDITDISTANCE_EDITDISTANCE_H
