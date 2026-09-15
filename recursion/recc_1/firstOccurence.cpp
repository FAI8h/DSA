#include <iostream>
#include <vector>

using namespace  std;

int firstOccur(vector<int> &nums,int tar, int i, int n){
    if(i == n) return -1;

    if(nums[i] == tar) return i;

    return firstOccur(nums, tar, i + 1, n);
}

int main () {
    vector<int> nums = {1, 2, 3, 3, 4, 5, 6};
    cout << firstOccur(nums, 3, 0, nums.size()) << endl;
    return 0;
}