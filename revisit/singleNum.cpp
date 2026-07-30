#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int singleNumber(vector<int>& nums){
    int ans = 0;
    for(int num : nums){
        ans ^= num;
    };
    return ans;
}

int main () {
    vector<int> nums = {1};
    cout << singleNumber(nums) << endl;
    return 0;
}