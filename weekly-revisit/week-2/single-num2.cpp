#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int singleNum2(vector<int> &nums){
    int ans = 0;
    for(int i = 0; i < 32; i++){
        int bitSum{0};

        for(int num : nums){
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
    vector<int> nums = {2,2,4,2};
    singleNum2(nums);
    return 0;
}