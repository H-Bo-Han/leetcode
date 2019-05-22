//
// Created by lutingting on 2017/11/23.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#ifndef DELETEOPERATIONFORTWOSTRINGS_DELETEOPERATION_H
#define DELETEOPERATIONFORTWOSTRINGS_DELETEOPERATION_H


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dis(n1+1, vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1]==word2[j-1]){
                    dis[i][j]=dis[i-1][j-1]+1;
                }
                else{
                    dis[i][j]=max(dis[i-1][j],dis[i][j-1]);
                }
            }
        }
        return n1+n2-2*dis[n1][n2];
    }
};





#endif //DELETEOPERATIONFORTWOSTRINGS_DELETEOPERATION_H
