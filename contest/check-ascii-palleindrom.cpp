#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>


using namespace  std;

string binString(int num){
    string s = "";
    for (int i = 7; i >= 0; --i){
        s += ((num >> i) & 1) ? '1' : '0';
    }
    return s;
}

bool isPalindromic(string s) {
    int n = s.length();
    unordered_map<char,string> m;
    for(int i = 0; i < n; i++){
        char ch = s[i];
        int charInteger = ch - 'a' + 1;
        string binaryS = binString(charInteger);

        m[ch] = binaryS;
        
    }
    for(auto & [key, val] : m){
        cout << key << " : " << val;
    }
    cout << endl;
    return true;
}

int main () {
    string s = "ff";
    isPalindromic(s);
    return 0;
}