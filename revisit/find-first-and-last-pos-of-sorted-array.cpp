#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;
int n;

int leftMost(vector<int> &nums,int tar){
    int ans = -1;
    int st{0},end{n-1};

    while(st <= end){
        int mid = st + (end - st) / 2;

        if(nums[mid] == tar){
            ans = mid;
            end = mid - 1;
        }else if(nums[mid] < tar){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}
int rightMost(vector<int> &nums,int tar){
    int ans = -1;
    int st{0},end{n-1};

    while(st <= end){
        int mid = st + (end - st) / 2;

        if(nums[mid] == tar){
            ans = mid;
            st = mid + 1;
        }else if(nums[mid] < tar){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

vector<int> firstAndLastPos(vector<int> &nums, int tar){
    n = nums.size();
    vector<int> ans;
    ans.push_back(leftMost(nums, tar));
    ans.push_back(rightMost(nums, tar));
    return ans;
}

int main () {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = firstAndLastPos(nums, 8);

    for(int num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}