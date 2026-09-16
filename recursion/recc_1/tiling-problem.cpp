#include <iostream>

using namespace  std;

int tilingWays(int tileL, int gridW){

    if(gridW == 0 || gridW == 1) return 1;

    int vertical = tilingWays(tileL, gridW - 1);

    int horizontal = tilingWays(tileL, gridW - 2);

    return vertical + horizontal;
}

int main () {

    cout << tilingWays(2, 4) << endl;

    return 0;
}