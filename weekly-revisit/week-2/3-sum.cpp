#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

vector<vector<int>> threeSum(vector<int> & nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left{0}, right(0);
    vector<vector<int>> ans;
    
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int tar = nums[i];
        left = i + 1;
        right = n - 1;

        while(left < right){
            int sum = nums[left] + nums[right];

            if(sum == -tar){
                ans.push_back({tar, nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
                continue;
            }

            if(sum > -tar){
                right--;
            }else{
                left++;
            }
        }
    }

    for(auto i : ans){
        for(auto n : i){
            cout << n << " ";
        }
        cout << endl;
    }

    return ans;
}

int main () {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum(nums);
    return 0;
}