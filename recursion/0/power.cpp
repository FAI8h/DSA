#include <iostream>

using namespace  std;
/*
int power(int x, int n){
    if(n == 0) return x;
    if(n == 1) return x;

    return x * (power(x, n - 1));
}

*/

int power(int x, int n){
    if(n == 0) return 1;
    int half = power(x, n / 2);

    return n % 2 ? half * half * x : half * half;
}

int main () {
    cout << "pow : " << power(2, 4) << endl;
    return 0;
}