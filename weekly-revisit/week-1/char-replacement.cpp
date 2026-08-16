#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int charReplacement(string s, int k){
    int n = s.size();
    int m[26] = {0};
    int left{0}, right{0}, freq{0},ans{0};

    for (int i = 0; i< n; i++){
        m[s[right] - 'A']++;

        freq = max(freq, m[s[right] - 'A']);

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
    charReplacement(s, 2);
    return 0;
}