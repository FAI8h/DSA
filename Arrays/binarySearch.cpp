#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int binarySearch(vector<int>& nums, int tar){
    int st = 0, end = nums.size() - 1;
    int mid = 0;
    
    while(st <= end){
        mid = st + (end - st) / 2;

        if(nums[mid] == tar){
            return mid;
        }

        if(nums[mid] < tar){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}

int main () {
    vector<int> nums = {-1, 0, 1, 3, 4, 7, 9, 12};
    cout << binarySearch(nums, 9);
    return 0;
}
