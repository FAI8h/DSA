#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int mostWater(vector<int>& height){
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left < right){
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, area);

        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }
    cout << maxArea << endl;
    return maxArea;
}

int main () {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    mostWater(height);
    return 0;
}