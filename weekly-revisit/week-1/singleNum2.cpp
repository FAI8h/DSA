#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int unique(vector<int> &nums){
    int n = nums.size();

    int ans = 0;

    for (int i = 0; i < 32; i++){//! imp it must loop through all the bits that's Y i < 32; cause of 32 bit integer
        int bitSum = 0;
        for (int num : nums){
            bitSum += (num >> i) & 1;
        }

        if(bitSum % 3){
            ans |= (1 << i);
        }
    }
    cout << ans << endl;
    return ans;
}

int main () {
    vector<int> nums = {2,3,2,7,3,2,3};
    unique(nums);
    return 0;
}