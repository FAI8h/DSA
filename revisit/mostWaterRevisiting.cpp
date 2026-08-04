#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int mostWater(vector<int> &height){
    int maxArea = 0;
    int st = 0, end = height.size() - 1;

    while(st < end){
        int area = min(height[st], height[end]) * (end - st);
        maxArea = max(maxArea, area);

        if(height[st] < height[end]){
            st++;
        }else{
            end--;
        }
    }
    cout << maxArea << " " << endl;
    return maxArea;
}

int main () {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    mostWater(height);
    return 0;
}