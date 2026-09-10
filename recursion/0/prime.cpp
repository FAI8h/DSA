#include <iostream>

using namespace  std;

bool isPrime(int num, int divisior = 2){
    if(num < 2){
        return false;
    }

    if(divisior * divisior > num){
        return true;
    }

    if(num % divisior == 0){
        return false;
    }

    return isPrime(num, divisior + 1);
}

void print(int m, int n){
    if(m > n){
        return;
    }

    if(isPrime(m)){
        cout << m << " " << endl;
    }

    print(m + 1, n);
}

int main () {
    print(0, 10);
    return 0;
}