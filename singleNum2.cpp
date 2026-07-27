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
*/

int singleNum(vector<int>& nums){
    int ans = 0;
    for(int num : nums){
        ans ^= num;
        cout << "loop : " << ans << endl;
    }
    cout << "ans : " << ans << endl;
    return ans;
}



int main () {
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNum(nums) << endl;
    return 0;
}