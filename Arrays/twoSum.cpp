#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

/*
! 1.
? TC :- O(n*n), SC :- O(n)
vector<int> twoSum(vector<int>& nums, int target){
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if((nums[i] + nums[j]) == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

! 2.
? TC :- O(n log n), SC :- O(n)
vector<int> twoSum(vector<int>& nums, int tar){
    vector<int> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int st = 0, end = n - 1;
    for (int i = 0; i < n; i++)
    {
        int currSum = nums[st] + nums[end];
        if(currSum == tar){
            ans.push_back(st);
            ans.push_back(end);
            break;
        }
        if(currSum > tar){
            end--;
        }else{
            st++;
        }
    };
    return ans;
}

! 3.
? TC :- O(n), SC :- O(n)
vector<int> twoSum(vector<int>& nums, int tar){
    vector<int> ans;
    int n = nums.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++){
        int x = nums[i];
        int y = tar - x;

        if(m.find(y) != m.end()){
            ans.push_back(m[y]);
            ans.push_back(i);
            break;
        }
        m[x] = i;
    }
    return ans;
}
*/

vector<int> twoSum(vector<int>& nums, int tar){
    vector<int> ans;
    int n = nums.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++){
        int x = nums[i];
        int y = tar - x;

        if(m.find(y) != m.end()){
            ans.push_back(m[y]);
            ans.push_back(i);
            break;
        }
        m[x] = i;
    }
    return ans;
}

int main () {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for(int num : ans){
        cout << num << " " << endl;
    }
    return 0;
}