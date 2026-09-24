#include <iostream>

using namespace  std;

int GDC(int a, int b){
    if(b == 0) return a;

    return GDC(b, a % b);// this is Euclidean algorithm
}

int main () {
    cout << GDC(48, 18) << endl;
    return 0;
}