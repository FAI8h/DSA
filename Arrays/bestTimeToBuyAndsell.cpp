#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int maxProfit(vector<int> &nums){
    int minPrice = nums[0];
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++){
        if(nums[i] < minPrice){
            minPrice = nums[i];
        }
        ans = max(ans, nums[i] - minPrice);
    }

    return ans;
}

int main () {
    vector<int> nums = {7,1,5,3,6,4};
    cout << maxProfit(nums) << endl;
    return 0;
}