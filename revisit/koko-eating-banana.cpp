#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int minEatingSpeed(vector<int> &nums, int h){
    int n = nums.size();
    int st{1}, end{0};
    end = *max_element(nums.begin(), nums.end());
    int k = 1;
    while(st <= end){
        int mid = st + (end - st) / 2;

        int hourUsed = 0;
        for (int i = 0; i < n; i++){
            hourUsed += (nums[i] + mid - 1) / mid;
        }

        if(hourUsed <= h){
            k = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return st;
}

int main () {
    vector<int> piles = {3, 6, 7, 11};
    cout << minEatingSpeed(piles, 4) << endl;
    return 0;
}