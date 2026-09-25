#include <iostream>
#include <string>
#include <vector>
using namespace  std;

void subSets(string s, string ans){
    if(s.length() == 0){
        cout << "["<< ans << "]"<<  endl;
        return;
    }

    subSets(s.substr(1, s.length() - 1), ans + s[0]);
    subSets(s.substr(1, s.length() - 1), ans);
}

void subSets(vector<int>& v, vector<int>& ans, int i){
    if(i == v.size()){
        for(auto it : ans){
            cout << "[ " << it << " ]";
        }
        cout << endl;
        return;
    }

    ans.push_back(v[i]);
    subSets(v, ans, i + 1);
    ans.pop_back();
    subSets(v, ans, i + 1);
}

int main () {
    vector<int> v{1, 2, 3};
    vector<int> ans;
    subSets(v,ans, 0);

    return 0;
}