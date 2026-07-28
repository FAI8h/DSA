#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

/*
! 1.
? TC : O(n), SC :- O(n)
int singleNum(vector<int>& nums){
    unordered_map<int, int> count;
    for(int num : nums){
        count[num]++;
    };

    for(int num : nums){
        if(count[num] == 1){
            return num;
        }
    }
    return -1;
}

! 2.
? TC :- O(n), SC :- O(1)
int singleNum(vector<int>& nums){
    int result = 0;
    for (int i = 0; i < 32; i++){
        int bitSum = 0;
        for(int num : nums){
            bitSum += (num >> i) & 1;
        };

        if(bitSum % 3){
            result |= (1 << i);
        }
    }
    return result;
}

*/

int singleNum(vector<int>& nums){
    int result = 0;
    for (int i = 0; i < 32; i++){
        int bitSum = 0;
        for(int num : nums){
            bitSum += (num >> i) & 1;
        };

        if(bitSum % 3){
            result |= (1 << i);
        }
    }
    return result;
}

int main () {
    vector<int> nums = {30000,500,100,30000,100,30000,100};
    cout << singleNum(nums) << endl;
    return 0;
}