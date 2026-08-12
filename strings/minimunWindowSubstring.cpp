#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>
using namespace  std;

//? leetCode Qno. 76

string minWindow(string s, string t){
    unordered_map<char, int> need;
    int req = 0;
    for(char c : t) need[c]++;
    req = need.size();
    unordered_map<char, int> m;
    int left = 0, right = 0;
    int minLen = INT_MAX, minStart = 0;

    for (int i = 0; i < s.size(); i++){
        m[s[right]]++;

        if(need.find(s[right]) != need.end() & need[s[right]] == m[s[right]]) req--;

        while(req == 0){
            if(right - left + 1 < minLen){
                minLen = right - left + 1;
                minStart = left;
            }
            m[s[left]]--;
            
            if(need.find(s[left]) != need.end() && need[s[left]] > m[s[left]]) req++;

            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main () {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t) << endl;
    return 0;
}