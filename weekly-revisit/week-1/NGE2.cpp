#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>
#include <stack>

using namespace  std;

vector<int> NGE2(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> s;

    for (int i = 0; i < 2*n; i++){
        int idx1 = i % n;
        while(!s.empty() && nums[idx1] > nums[s.top()]){
            int idx = s.top();
            s.pop();
            ans[idx] = nums[idx1];
        }
        if(i < n){
            s.push(i);
        }
    }

    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;
    return ans;
}

int main () {
    vector<int> nums = {1, 2, 1};
    NGE2(nums);
    return 0;
}