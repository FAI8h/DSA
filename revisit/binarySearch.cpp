#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int binarySearch(vector<int>& nums,int tar){
    int st = 0, end = nums.size() - 1;
    int mid = 0;
    while(st <= end){
        mid = st + (end - st) / 2;

        if(nums[mid] == tar){
            return mid;
        };

        if(nums[mid] < tar){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    };

    return mid;
}

int main () {
    vector<int> nums = {1,3,7,12,15,19};
    cout << binarySearch(nums, 12) << endl;
    return 0;
}