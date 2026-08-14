#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;

//? leetCode Qno. 567

bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char,int> window;
        unordered_map<char,int> need;
        int req = 0;
        for(char ch : s1) need[ch]++;
        req = need.size();

        int n = s2.size(), windowSize = s1.size();
        int left = 0, right = windowSize;
        for(int i = 0; i < windowSize; i++) window[s2[i]]++;

        for(auto &[ch, val] : need){
            if(window.find(ch) != window.end() && window[ch] == need[ch]) req--;
        }

        if(req == 0) return true;
        
        while(right < n){

            if(need.find(s2[right]) != need.end() && need[s2[right]] == window[s2[right]]) req++;
            window[s2[right]]++;
            if(need.find(s2[right]) != need.end() && need[s2[right]] == window[s2[right]]) req--;

            if(need.find(s2[left]) != need.end() && need[s2[left]] == window[s2[left]]) req++;
            window[s2[left]]--;
            if(need.find(s2[left]) != need.end() && need[s2[left]] == window[s2[left]]) req--;

            left++;
            right++;

            if(req == 0) return true;
        }

        return false;
    }

int main () {
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1,s2)<<endl;

    return 0;
}