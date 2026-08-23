#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int splitArray(vector<int> &nums, int k){
    int n = nums.size();
    int left{0}, right{0};
    left = *max_element(nums.begin(), nums.end());
    for(int num : nums) right += num;
    int ans = INT_MAX;
    while (left <= right){
        int candidate = left + (right - left) / 2;
        int pices = 1, currSum = 0;

        for(int x : nums){
            if(currSum + x <= candidate){
                currSum += x;
            }else{
                pices++;
                currSum = x;
            }
        }

        if(pices <= k){
            ans = min(ans, candidate);
            right = candidate - 1;
        }else{
            left = candidate + 1;
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {7, 2, 5, 10, 8};
    splitArray(nums, 2);
    return 0;
}