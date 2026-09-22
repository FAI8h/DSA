#include <iostream>
#include <vector>

using namespace  std;

void allIndex(vector<int> &nums, int n, int i){
    if(i == nums.size()) return;

    if(nums[i] == n) cout << i << "\n";

    return allIndex(nums, n, i + 1);
}

int main () {
    vector<int> nums = {1, 2, 3, 5, 6, 2, 7, 2, 2};
    allIndex(nums, 8, 0);

    return 0;
}