#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int cap(vector<int> &w, int d){
    int n = w.size();
    int st{0}, end{0};
    st = *max_element(w.begin(), w.end());
    for(int num : w) end += num;
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st) / 2;

        int dayUsed{1}, totalCap{0};
        for(int x : w){
            if(totalCap + x <= mid){
                totalCap += x;
            }else{
                dayUsed++;
                totalCap = x;
            }
        }

        if(dayUsed <= d){
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}

int main () {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << cap(weights, 5) << endl;
    return 0;
}