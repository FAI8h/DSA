#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace  std;

vector<int> dailyTemp(vector<int> &temps){
    vector<int> ans(temps.size(),0);
    stack<int> s;

    for (int i = 0; i < temps.size(); i++){
        while(!s.empty() && temps[i] > temps[s.top()]){
            int prevDay = s.top();
            s.pop();
            ans[prevDay] = i - prevDay;
        }
        s.push(i);
    }

    return ans;
}

int main () {
    vector<int> temp = {73,74,75,71,69,72,76,73};

    vector<int> ans = dailyTemp(temp);
    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}