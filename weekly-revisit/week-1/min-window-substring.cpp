#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;


/*
! Try Optmizing
string minWindow(string s, string t) {
        int n  = s.size(),windowSize = t.size();
        int need[26] = {0}, window[26] = {0};
        int left{0},right{0},freq{0},minStart{0},minLen{INT_MAX};

        for(int i = 0; i < windowSize; i++) {
            need[tolower(t[i]) - 'a']++;
            if(need[tolower(t[i]) - 'a'] == 1){
                freq++;
            }
        }

        for(int i = 0; i < n; i++){
            int ridx = tolower(s[right]) - 'a';
            window[ridx]++;

            if(need[ridx] > 0 && need[ridx] == window[ridx]) freq--;


            while(freq == 0){
                int lidx = tolower(s[left]) - 'a';
                window[lidx]--;

                if((right - left + 1) > minLen){
                    minLen = right - left + 1;
                    minStart = left;
                }

                if(need[lidx] > 0 && need[lidx] > window[lidx]) freq++;
                left++;
            }
            right++;

        }
        return minLen == INT_MAX ? "" : s.substr(minStart,minLen);

    }

*/

//? leetCode Qno. 76
string minWindow(string s,string t){
    int n = s.length(),windowSize = t.length();
    unordered_map<char,int> need;
    unordered_map<char,int> window;

    for(char ch : t) need[ch]++;
    int freq = need.size();
    int left{0}, right{0},minStart{0},minLen{INT_MAX};
    for (int i = 0; i < n; i++){
        window[s[right]]++;

        if(need.find(s[right]) != need.end() && need[s[right]] == window[s[right]]) freq--;

        while(freq == 0){
            if((right - left + 1) < minLen){
                minLen = right - left + 1;
                minStart = left;
            }
            window[s[left]]--;

            if(need.find(s[left]) != need.end() && need[s[left]] > window[s[left]]) freq++;

            left++;
        }
        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main () {
    string s = "baaacacnbba";
    string t = "abc";

    cout << minWindow(s, t) << endl;
    return 0;
}