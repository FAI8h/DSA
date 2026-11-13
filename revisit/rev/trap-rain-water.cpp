#include <iostream>
#include <vector>

using namespace std;

int water(vector<int>& height){
    int n = height.size();
    int leftMax{0}, rightMax{0}, left{0}, right{n-1}, ans{0};

    while(left < right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax){
                leftMax = height[left];
            }else{
                ans += leftMax - height[left];
            }
            left++;
        }else{
			if(height[right] >= rightMax){
				rightMax = height[right];
			}else{
				ans += rightMax - height[right];
			}
			right--;
		}
	}
	cout << ans << " \n";
	return ans;
}

int main () {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	water(height);

	return 0;
}