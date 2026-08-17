#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;

int subStr(string s){
    int n = s.size();
    unordered_map<char, int> window;

    int left{0}, right{0},ans{0};

    for (int i = 0; i < n; i++){
        if(window.find(s[right]) != window.end()){
            left = max(left, window[s[right]] + 1);
        }
        window[s[right]] = right;
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main () {
    string s = "abcabcbb";
    cout << subStr(s) << endl;
    return 0;
}