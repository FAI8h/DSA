#include <iostream>
#include <algorithm>

using namespace  std;

int NumberOf1Bits(int n){
    int count = 0;

    while(n > 0){
        if(n & 1) count++;

        n = n >> 1;
    };

    return count;
}

int main () {
    cout << NumberOf1Bits(128) << endl;

    return 0;
}