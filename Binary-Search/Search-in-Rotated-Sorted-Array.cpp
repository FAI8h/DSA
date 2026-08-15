#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int returnIndex(vector<int> &nums, int target){
    int n = nums.size();
    int st{0}, mid{0}, end{n - 1};

    while(st <= end){
        mid = st + (end - st) / 2;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] >= nums[st]){
            if(nums[st] <= target && target < nums[mid]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if(nums[mid] < target && target <= nums[end]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }

    }

    return -1;
}

int main () {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << returnIndex(nums, 3) << endl;

    return 0;
}