#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int binarySearch(vector<int> &nums,int target){
    int n = nums.size();
    int st{0}, mid{0}, end{n-1};
    
    while(st <= end){
        mid = st + (end - st) / 2;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] > target){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    return -1;
}

int main () {
    vector<int> nums = {1, 2, 4, 7, 9, 15};

    cout << binarySearch(nums, 9) << endl;
    return 0;
}