#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int countSetBit(int num){
    int ans = 0;
    int it = 1;
    while (num != 0)
    {
        int result = num & 1;
        ans += result;
        num = (num >> 1);
    };
    return ans;
}

int main () {
    int num = 3;
    cout << countSetBit(num) << endl;
    return 0;
}