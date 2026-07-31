#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace  std;

vector<int> findRepAndMissing(vector<vector<int>>& nums){
    int n = nums.size();
    int actualSum = ((n * n) * ((n * n) + 1)) / 2;
    int currSum = 0;
    unordered_set<int> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            currSum += nums[i][j];
            if(s.find(nums[i][j]) != s.end()){
                a = nums[i][j];
            }
            s.insert(nums[i][j]);
        }
    }

    b = actualSum + a - currSum;
    return {a, b};
}

int main () {
    vector<vector<int>> nums = {{1,3},{2,2}};
    vector<int> result = findRepAndMissing(nums);
    for(int num : result){
        cout << num << "  " << endl;
    }
    return 0;
}