#include <iostream>

using namespace  std;

// int pairFriends(int n){

//     if(n == 1) return 1;
//     if(n == 2) return 2;

//     return pairFriends(n-1) + (n-1) * pairFriends(n - 2);
// };

int pairFriends(int n){

    if(n == 1) return 1;
    if(n == 2) return 2;

    int single = pairFriends(n - 1);

    int pair = (n - 1) * pairFriends(n - 2);

    return single + pair;
};

int main () {

    cout << pairFriends(4) << endl;

    return 0;
}