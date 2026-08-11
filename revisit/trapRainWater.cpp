#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

//? leetCode Qno. 42

int rainWater(vector<int> &height){
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int trapWater = 0;

    while(left < right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax){
                leftMax = height[left];
            }else{
                trapWater += leftMax - height[left];
            }
            left++;
        }else{
            if(height[right] >= rightMax){
                rightMax = height[right];
            }else{
                trapWater += rightMax - height[right];
            }
            right--;
        }
    }
    return trapWater;
}

int main () {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainWater(height)<<endl;
    return 0;
}