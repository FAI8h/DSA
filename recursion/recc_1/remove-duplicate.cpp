#include <iostream>
#include <vector>

using namespace  std;

string removeDuplicate(string s, int i, vector<bool> & seen, string n){
    if(i == s.length()) return n;
    
    if(!seen[s[i] - 'a']){
        n += s[i];
        seen[s[i] - 'a'] = true;
    }
    
    return removeDuplicate(s, i + 1, seen, n);
}

int main () {

    string s = "ssaazzaar";
    vector<bool> seen(26, false);

    cout << removeDuplicate(s, 0, seen, "") << endl;

    return 0;
}