#ifndef REMOVEDUPLICATESFROMSORTEDARRAY_LIBRARY_H
#define REMOVEDUPLICATESFROMSORTEDARRAY_LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
int removeDuplicates(vector<int> &vec){
    if(vec.empty()){
        return 0;
    }
    int *p=&vec[0];
    int cnt = vec.size();
    vector<int>::iterator it = vec.begin();
    for(int i=1; i < vec.size(); ++i){
        if((*(p+1)-*p)==0){
            cnt--;
        }
        ++p;
    }
    return cnt;
}
};

#endif