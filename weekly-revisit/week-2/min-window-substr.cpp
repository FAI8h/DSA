#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;

bool isEqual(int need[], int window[]){
    for(int i = 0; i < 26; i++){
        if(need[i] != window[i]){
            return false;
        }
    }
    return true;
}

string minWIndow(string s, string t){
    int n1 = s.length(), n2 = t.length();
    unordered_map<char, int> need;
    unordered_map<char, int> window;
    int freq{0};
    for(char ch : t){
        need[ch]++;
    }
    freq = need.size();

    int left{0}, right{0}, minSt{0}, minLen{INT_MAX};

    for (int i = 0; i < n1; i++)
    {
        char ch = s[right];
        window[ch]++;

        if(need[ch] != 0 && window[ch] == need[ch]) freq--;

        while(freq == 0){
            if((right - left + 1) < minLen){
                minSt = left;
                minLen = right - left + 1;
            }

            window[s[left]]--;

            if(need[s[left]] != 0 && need[s[left]] > window[s[left]]) freq++;

            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minSt, minLen);
}

int main () {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWIndow(s, t) << endl;
    return 0;
}