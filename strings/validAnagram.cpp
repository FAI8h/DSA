#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace  std;

/*
bool validAnagram(string s, string t){
    unordered_map<char, int> m;

    for(char c : s){
        m[c]++;
    }

    for(char c : t){
        if(!(m.find(c) != m.end())){
            return false;
        }
        m[c]--;
        if(m[c] == 0){
            m.erase(c);
        }
    }

    return m.size() == 0;
}
*/

bool validAnagram(string s, string t){
    if(s.size() != t.size()) return false;

    int count[26] = {0};

    for (int i = 0; i < s.size(); i++){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++){
        if(count[i] != 0){
            return false;
        }
    }

    return true;
}

int main () {
    string s = "anagram";
    string t = "nagaram";

    cout << validAnagram(s, t) <<endl;
    return 0;
}