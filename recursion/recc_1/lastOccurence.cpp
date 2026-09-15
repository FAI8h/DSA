#include <iostream>
#include <vector>

using namespace  std;

int lastOccur(vector<int> &nums, int tar, int i){
    if(i == nums.size()) return -1;

    int idx = lastOccur(nums, tar, i + 1);

    if(idx == -1 && nums[i] == tar) return i;

    return idx;
}

int main () {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5, 6};

    cout << lastOccur(nums, 5, 0) << endl;
    return 0;
}