#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

int majorityElem(vector<int> nums){
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        m[nums[i]]++;
        if(m[nums[i]] > n / 2){
            return nums[i];
        }
    };

    return -1;
}

int main () {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElem(nums) << endl;
    return 0;
}