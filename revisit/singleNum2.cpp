#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int singleNum2(vector<int>& nums){
    int ans = 0;

    for (int i = 0; i < 32; i++){
        int bitmask = 0;
        for(int num : nums){
            bitmask += (num >> i) & 1;
        }

        if(bitmask % 3){
            ans |= (1 << i);
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << singleNum2(nums) << endl;
    return 0;
}