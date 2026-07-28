#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace  std;

vector<int> findRepAndMissing(vector<vector<int>>& nums){//? TC :- O(n*n), SC :- O(n)
    vector<int> ans;
    int n = nums.size();
    int totalSum = ((n * n) * ((n * n) + 1)) / 2;
    unordered_set<int> s;
    int a, b;
    int currSum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            currSum += nums[i][j];
            if(s.find(nums[i][j]) != s.end()){
                a = nums[i][j];
            };
            s.insert(nums[i][j]);
        }
    }
    b = (totalSum - currSum) + a;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main () {
    vector<vector<int>> nums = {{1,3},{2,2}};
    vector<int> res = findRepAndMissing(nums);
    for(int num : res){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}