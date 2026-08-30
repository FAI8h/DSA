#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;

int subString(string s){
    int n = s.length();
    unordered_map<char, int> m;
    int left{0}, right{0}, freq{0};
    int ans = 0;
    for (int i = 0; i < n; i++){
        if(m.find(s[right]) != m.end()){
            left = max(left, m[s[right]] + 1);
        }

        m[s[right]] = right;
        ans = right - left + 1;
        right++;
    }
    cout << ans << endl;
    return ans;
}

int main () {
    string s = "pwwkew";
    subString(s);
    return 0;
}