#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace  std;

/*
! 1.
? TC :- O(n), SC :- O(n)

int singleNum(vector<int>& nums){
    unordered_map<int, int> count;
    int n = nums.size();

    for(int num : nums){//? insertion
        count[num]++;
    };

    for(int num : nums){//? finding
        if(count[num] == 1){
            return num;
        }
    }

    return -1;
}


! 2.
? TC :- O(n), SC :- O(1)
int singleNum(vector<int>& nums){
    int ans = 0;
    for (int num : nums){
        ans ^= num;
    }

    return ans;
}

*/

int singleNum(vector<int>& nums){
    int ans = 0;
    for (int num : nums){
        ans ^= num;
    }

    return ans;
}

int main () {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNum(nums) << endl;

    return 0;
}