#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace  std;

//? leetCode Qno. 209

int windowSize(vector<int> &nums,int tar){
    int left = 0, right = 0;
    int ans = INT_MAX;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++){
        sum += nums[right];

        while(sum >= tar){
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return ans == INT_MAX ? 0 : ans;
}

int main () {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << windowSize(nums,7) << endl;
    return 0;
}