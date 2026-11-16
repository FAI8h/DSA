#include <iostream>
#include <vector>

using namespace  std;

int majorityElem(vector<int>& nums){
    int n = nums.size();
    int currElem = nums[0], vote = 1;
    for (int i = 1; i < n; i++){
        if(vote <= 0) {
            currElem = nums[i];
            vote++;
        }
        if(nums[i] == currElem){
            vote++;
        }else{
            vote--;
        }
    }
    cout << currElem << endl;
    return currElem;
};

int main () {
    vector<int> nums = {2, 2, 2, 1, 1, 2, 1};
    majorityElem(nums);
    return 0;
}