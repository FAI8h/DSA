#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

/*
! 1.
? TC :- O(n), SC :- O(n)
vector<int> singleNum(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> m;

    for(int num : nums){
        m[num]++;
    };
    for (int num : nums){
        if(m[num] == 1){
            ans.push_back(num);
        }
    }
    return ans;
}

*/

vector<int> singleNum(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> m;

    for(int num : nums){
        m[num]++;
    };
    for (int num : nums){
        if(m[num] == 1){
            ans.push_back(num);
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> res = singleNum(nums);
    for(int num : res){
        cout << num << " " << endl;
    }

    return 0;
}