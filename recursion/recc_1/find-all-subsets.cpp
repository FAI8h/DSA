#include <iostream>
#include <string>

using namespace  std;

void subSets(string s, string ans){
    if(s.length() == 0){
        cout << "["<< ans << "]"<<  endl;
        return;
    }

    subSets(s.substr(1, s.length() - 1), ans + s[0]);
    subSets(s.substr(1, s.length() - 1), ans);
}

int main () {
    subSets("12345", "");

    return 0;
}