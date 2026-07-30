#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

vector<int> singleNum3(vector<int>& nums){
    long long int xorAll = 0;
    for(int num : nums){
        xorAll ^= num;
    };

    long long int diffBit = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int num : nums){
        if(diffBit & num){
            a ^= num;
        }else{
            b ^= num;
        }
    }
    cout << a << " " << b << endl;
    return {a, b};
}

int main () {
    vector<int> nums = {2, 3, 2, 5, 3, 7};
    singleNum3(nums);
    return 0;
}