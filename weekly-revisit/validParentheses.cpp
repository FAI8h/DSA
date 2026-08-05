#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace  std;

bool validPrentheses(string b){
    stack<char> s;

    for(char c : b){
        if(c == '{' || c == '[' || c == '('){
            s.push(c);
        }else{
            if(s.empty()) return false;
            //||  || c == ')'

            if(c == '}' && s.top() == '{'){
                s.pop();
            }else if(c == ']' && s.top() == '['){
                s.pop();
            }else if(c == ')' && s.top() == '('){
                s.pop();
            }
        }
    }

    return s.empty();
}

int main () {
    string b = "({[()]})";//? valid
    // string b = "({[(]})";//! invalid

    cout << validPrentheses(b) << endl;

    return 0;
}