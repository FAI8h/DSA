#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

vector<int> twoSum(vector<int> &nums, int tar){
    int n = nums.size();
    int left = 0, right = n - 1;

    while(left <right){
        if(nums[left] + nums[right] == tar){
            return {left + 1, right + 1};
        }else{
            if(nums[left] + nums[right] > tar){
                right--;
            }else{
                left++;
            }
        }
    }
    return {-1, -1};
}

int main () {
    vector<int> nums = {-1, 0};
    vector<int> ans = twoSum(nums, -1);
    for(int num : ans){
        cout << num <<" ";
    }
    cout << endl;

    return 0;
}