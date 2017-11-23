#include <iostream>
#include "EditDistance.h"
/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

using namespace std;
int main() {
    string word1="intension";
    string word2="exection";
    Solution *s=new Solution();
    int ans=s->minDistance(word1,word2);
    cout<<"Distance: "<<ans<<endl;
    return 0;
}