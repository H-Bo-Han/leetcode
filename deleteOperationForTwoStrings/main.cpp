#include <iostream>
#include <string>
#include "DeleteOperation.h"
using namespace std;

/*

Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same,
 where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
    1. The length of given words won't exceed 500.
    2. Characters in given words can only be lower-case letters.

*/

int main() {
    string word1="tea";
    string word2="sea";
    Solution *s=new Solution();
    int ans=s->minDistance(word1,word2);
    cout<<"Distance: "<<ans<<endl;
    return 0;
}