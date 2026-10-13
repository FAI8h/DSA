#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> m;
    vector<int> v;
    int n = nums.size();

    for (int i = 0; i < n; i++){
        int x = nums[i];
        int y = target - x;

        if(m.find(y) != m.end()){
            v.push_back(i);
            v.push_back(m[y]);
            break;
        };

        m[x] = i;
    }

    return v;
}

int main (){
    vector<int> nums = {2, 4, 5, 1, 7};
    int target = 11;

    for(auto i : twoSum(nums, target)){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}