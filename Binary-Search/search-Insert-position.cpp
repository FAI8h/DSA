#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

//? leetCode Qno. 35

int serachIdx(vector<int> &nums, int target){
    int n = nums.size();
    int st{0},mid{0},end(n-1);

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

    return st;
}

int main () {
    vector<int> nums = {1, 3, 5, 9, 11};
    cout << serachIdx(nums, -1) << endl;
    return 0;
}