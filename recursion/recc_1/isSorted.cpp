#include <iostream>
#include <vector>

using namespace  std;

bool isSorted(vector<int> & nums, int i){
    if(nums.size() == i) return true;

    if(i > 0 && nums[i] < nums[i - 1]) return false;

    return isSorted(nums, i + 1);
}

int main () {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << isSorted(nums, 0) << endl;

    return 0;
}