#include <iostream>

using namespace  std;

int NumberOfChanges(int n, int k){
    if((n & k) != k) return -1;

    return __popcount(static_cast<unsigned int>(n ^ k));
}

int main () {
    cout << NumberOfChanges(13, 4) << endl;
    return 0;
}