#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

bool search(vector<int> &nums, int tar){
    int n = nums.size();
    int st{0}, end{n-1};

    while(st <= end){
        int mid = st + (end - st) / 2;

        if(nums[mid] == tar) {
            cout << "true"<<endl;
            return true;
        }

        if(nums[mid] == nums[st] && nums[mid] == nums[end]){
            st++;
            end--;
            continue;
        }

        if(nums[mid] >= nums[st]){
            if(nums[st] <= tar && tar < nums[mid]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if(nums[mid] < tar && tar <= nums[end]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    cout << "false" << endl;
    return false;
}

int main () {
    vector<int> nums = {1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};
    search(nums, 13);
    return 5;
}