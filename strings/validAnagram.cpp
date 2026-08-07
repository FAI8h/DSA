#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace  std;

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

int main () {
    string s = "anagram";
    string t = "nagara";

    cout << validAnagram(s, t) <<endl;
    return 0;
}