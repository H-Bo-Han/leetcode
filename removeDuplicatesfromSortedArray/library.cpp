#include "library.h"

#include <iostream>
#include <vector>

int main(){
    vector<int> res = {1,1,2,3,4,4,5,6,6,7,8,9,9,10,11,12,13,13,14};
    Solution so = Solution();
    int ans = so.removeDuplicates(res);
    cout<<ans<<endl;
    return 0;
}

