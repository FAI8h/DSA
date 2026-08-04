#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace  std;

vector<int> NGE(vector<int> &nums1, vector<int> &nums2){
    vector<int> ans;
    unordered_map<int, int> um;
    stack<int> s;

    //? first solve it like daily temp ?? forget about nums1
    for (int i = 0; i < nums2.size(); i++){
        while(!s.empty() && nums2[i] > nums2[s.top()]){
            int idx = s.top();
            s.pop();
            um[nums2[idx]] = nums2[i];
        };
        s.push(i);
    }
    
    //? now assign -1 to the remaning elem in stack
    while(!s.empty()){
        um[nums2[s.top()]] = -1;
        s.pop();
    }

    //? just look up and push_back the ans 
    for(int num : nums1){
        ans.push_back(um[num]);
    }

    return ans;
}

int main () {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> ans = NGE(nums1, nums2);

    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}