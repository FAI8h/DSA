#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int findPeakElement(vector<int>& nums) {//? this Algo dosen't guarantee the over all peak element it gives a local peak element
    int n = nums.size();
    int st{0},end{n - 1};
    while(st <= end){
        int mid = st + (end - st) / 2;

        if(mid < n - 1&&nums[mid] < nums[mid + 1]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
        
    }

    return st;
}

int main () {
    vector<int> nums = {1,2,4,3,1,6,4};
    cout << findPeakElement(nums) << endl;
    return 0;
}