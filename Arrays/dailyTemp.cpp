#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace  std;

vector<int> dailyTemp(vector<int> &temp){
    vector<int> ans(temp.size(),0);
    stack<int> st;
    for (int i = 0; i < temp.size(); i++){
        while(!st.empty() && temp[i] >temp[st.top()]){
            int prevDay = st.top();
            st.pop();
            ans[prevDay] = i - prevDay;
        }
        st.push(i);
    }

    return ans;
}

int main () {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> res = dailyTemp(temp);
    for (int day: res){
        cout << day << " ";
    };
    cout << endl;
    return 0;
}