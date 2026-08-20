#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int repeatingChar(string s, int k){
    int n = s.length();
    int m[26] = {0};
    int ans{0}, left{0}, right{0};
    int freq{0};
    for (int i = 0; i < n; i++){
        int idx = s[right] - 'A';
        m[idx]++;
        freq = max(freq, m[idx]);

        if((right - left + 1) - freq > k){
            m[s[left] - 'A']--;
            left++;
        }
        ans = right - left + 1;
        right++;
    }
    cout << ans << endl;
    return ans;
}

int main () {
    string s = "ABAB";
    repeatingChar(s, 2);
    return 0;
}