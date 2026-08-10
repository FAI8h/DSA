#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace  std;

int longestSubString(string s){
    int n = s.size();
    int left = 0, right = 0;
    int ans = 0;
    unordered_map<char, int> m;

    for (int i = 0; i < n; i++){
        if(m.find(s[right]) != m.end()){
            left = max(left, m[s[right]] + 1);
        }
        m[s[right]] = right;
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main () {
    string s = "abcabcbb";
    cout << longestSubString(s) << endl;
    return 0;
}