#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

vector<vector<int>> threeSum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = 0;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int tar = nums[i];
        left = i + 1;
        right = n - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == -tar){
                ans.push_back({tar, nums[left], nums[right]});
                /*
                    ? below code skips the duplicate values for the current iteration of --> i
                    ? but the left and right pointer always points to the last duplicat val
                    ? to make the left and right pointer point to the new val we update both pointer
                    ? cause we are at the new value thats Y we skips the current while loop iteration using continue;
                */
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
    return ans;
}

int main () {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    for(vector<int> i : ans){
        for(int num : i){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}