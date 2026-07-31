#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int countSetBit(int n){
    int ans = 0;

    while(n != 0){
        int lastBit = n & 1;
        ans += lastBit;
        n = n >> 1;
    };

    return ans;
}

int main () {
    int n = 7;
    cout << countSetBit(n) << endl;
    return 0;
}