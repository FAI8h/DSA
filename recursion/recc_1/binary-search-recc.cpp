#include <iostream>
#include <vector>

using namespace  std;

int binarySearch(vector<int>& nums, int tar, int st, int end){
    if(st > end) return -1;

    int mid = st + (end - st) / 2;
    if(nums[mid] == tar) {
        cout << mid << "\n";
        return mid;
    }

    if(nums[mid] > tar){
        return binarySearch(nums, tar, st, mid - 1);
    }else{
        return binarySearch(nums, tar, mid + 1, end);
    }
}

int main () {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    binarySearch(nums, 1, 0, nums.size() - 1);

    return 0;
}