#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int maxWater(vector<int> &heights){
    int n = heights.size();
    int left{0}, right{n - 1};
    int leftMax{0}, rightMax{0};
    int ans{0};

    while(left < right){
        if(heights[left] <= heights[right]){
            if(heights[left] >= leftMax){
                leftMax = heights[left];
            }else{
                ans += leftMax - heights[left];
            }
            left++;
        }else{
            if(heights[right] >= rightMax){
                rightMax = heights[right];
            }else{
                ans += rightMax - heights[right];
            }
            right--;
        }
    }
    cout << ans << endl;
    return ans;
}

int main () {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    maxWater(heights);
    return 0;
}