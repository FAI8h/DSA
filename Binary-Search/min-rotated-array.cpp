#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int minNum(vector<int> &nums){
    int n = nums.size();
    int st{0}, mid{0}, end{n - 1};
    int ans = INT_MAX;
    while(st <= end){
        mid = st + (end - st) / 2;

        ans = min(ans, nums[mid]);

        if(nums[mid] > nums[end]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << minNum(nums) << endl;
    return 0;
}