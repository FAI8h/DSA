#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace  std;

int findRepating(vector<int>& nums){
    int n = nums.size();
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    };

    return slow;
}

int main () {
    vector<int> nums = {1,3,4,2,2};
    cout << findRepating(nums) << endl;
    return 0;
}