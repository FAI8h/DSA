#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int eatingSpeed(vector<int> &piles,int h){
    int n = piles.size();
    int st = {1}, end{0};
    end = *max_element(piles.begin(), piles.end());

    while(st <= end){
        int mid = st + (end - st) / 2;
        int totalHour = 0;

        for (int i = 0; i < n; i++){
            totalHour += (piles[i] + mid - 1) / mid;
        }

        if(totalHour <= h){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    return st;
}

int main () {
    vector<int> piles = {3,6,7,11};
    cout << eatingSpeed(piles, 8) << endl;
    return 0;
}