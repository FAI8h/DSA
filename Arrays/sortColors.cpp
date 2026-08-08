#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

void sortColors(vector<int> &nums){
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main () {
    vector<int> nums = {2, 0, 1, 2, 1, 0};
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    sortColors(nums);
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}