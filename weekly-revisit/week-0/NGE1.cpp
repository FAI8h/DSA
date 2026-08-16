#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace  std;

vector<int> NGE1(vector<int> &nums1, vector<int> &nums2){
    stack<int> s;
    unordered_map<int, int> m;

    for (int i = 0; i < nums2.size(); i++){
        while (!s.empty() && nums2[i] > nums2[s.top()]){
            int idx = s.top();
            s.pop();
            m[nums2[idx]] = nums2[i];
        }
        s.push(i);
    }

    while(!s.empty()){
        m[nums2[s.top()]] = -1;
        s.pop();
    }

    vector<int> ans;
    for(int num : nums1){
        ans.push_back(m[num]);
    }

    return ans;
}

int main () {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> ans = NGE1(nums1, nums2);
    for(int num : ans){
        cout << num << " ";
    };
    cout << endl;
    return 0;
}