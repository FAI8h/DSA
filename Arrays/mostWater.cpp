#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int mostWater(vector<int>& heights){
    int maxArea = 0;
    int left = 0, right = heights.size() - 1;
    while (left < right){
        int area = min(heights[right], heights[left]) * (right - left);
        maxArea = max(maxArea, area);

        if(heights[left] < heights[right]){
            left++;
        }else{
            right--;
        };
    }

    return maxArea;
}

int main () {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << mostWater(heights) << endl;
    return 0;
}