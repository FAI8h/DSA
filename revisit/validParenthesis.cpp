#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace  std;

bool validParantheses(string& s){
    stack<char> container;

    for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            container.push(ch);
        }

        if(ch == ')' || ch == '}' || ch == ']'){
            if(container.empty()) return false;

            if (ch == ')' && container.top() == '(')
            {
                container.pop();
            }
            else if (ch == '}' && container.top() == '{')
            {
                container.pop();
            }
            else if (ch == ']' && container.top() == '[')
            {
                container.pop();
            }else{
                return false;
            }
        }
    }

    return container.empty();
}

int main () {
    string s = "((})";
    cout << validParantheses(s) << endl;
    return 0;
}