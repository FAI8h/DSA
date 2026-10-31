#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

vector<int> CountBits(int n){
    vector<int> ans(n + 1, -1);

    for (int idx = 0; idx <= n; idx++){
        int count = 0;
        int i = idx;
        while (i > 0){
            if(i & 1) count ++;
            i = i >> 1;
        };
        ans[idx] = count;
    };

    return ans;
}

int main () {
    for(auto it : CountBits(2)){
        cout << it << " ";
    };
    cout << endl;
    return 0;
}