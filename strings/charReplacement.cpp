#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace  std;

//? leetCode Qno. 424

int replaceChar(string s, int k){
    int n = s.size();
    int maxWindow = 0, maxFrq = 0;
    int left = 0, right = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++){
        if(m.find(s[right]) != m.end()){
            m[s[right]]++;
        }else{
            m[s[right]] = 1;
        }
        maxFrq = max(maxFrq, m[s[right]]);
        
        if((right - left + 1) - maxFrq > k){
            m[s[left]]--;
            left++;
        }
        maxWindow = right - left + 1;
        right++;
    }
    return maxWindow;
}

int main () {
    string s = "AAABABBBBA";
    cout << replaceChar(s, 1)<<endl;
    return 0;
}