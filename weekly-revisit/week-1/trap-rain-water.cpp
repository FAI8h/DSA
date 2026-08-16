#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int trappedWater(vector<int> &heights){
    int n = heights.size();
    int water{0};
    int left{0}, right{n - 1}, leftMax{0}, rightMax{0};

    for (int i = 0; i < n; i++)
    {
        if(heights[left] <= heights[right]){
            if(heights[left] >= leftMax){
                leftMax = heights[left];
            }else{
                water += leftMax - heights[left];
            }
            left++;
        }else{
            if(heights[right] >= rightMax){
                rightMax = heights[right];
            }else{
                water += rightMax - heights[right];
            }
            right--;
        }
    }
    cout << water << endl;
    return water;
}

int main () {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    trappedWater(heights);
    return 0;
}