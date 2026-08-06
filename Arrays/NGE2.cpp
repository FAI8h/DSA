#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace  std;

vector<int> NGE2(vector<int> &nums){
    stack<int> s;
    vector<int> ans(nums.size(), -1);

    for (int i = 0; i < 2 * nums.size(); i++){
        int idx = i % nums.size();

        while(!s.empty() && nums[idx] > nums[s.top()]){
            int idx0 = s.top();
            s.pop();
            ans[idx0] = nums[idx];
        };

        if(i < nums.size()){
            s.push(i);
        }
    }

    return ans;
}

int main () {
    vector<int> nums = {1, 2, 1};
    vector<int> ans = NGE2(nums);

    for(int num : ans){
        cout << num << " ";
    };
    cout << endl;
    return 0;
}