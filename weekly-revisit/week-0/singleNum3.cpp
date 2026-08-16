#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

vector<int> singleNum3(vector<int> &nums){
    long long int xorAll = 0;
    for(int num : nums){
        xorAll ^= num;
    }

    long long int diffBit = xorAll & (-xorAll);

    int a = 0, b = 0;
    for(int num : nums){
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
    vector<int> nums = {0, 1, 0, 1, 99, 7};
    singleNum3(nums);
    return 0;
}