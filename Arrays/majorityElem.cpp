#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

/*
? this works but this is a bad approch ---
? sorting is expensive ---  TC :- O(n log n), SC :- O(1)

int majorityElem(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
*/


int majorityElem(vector<int>& nums){
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