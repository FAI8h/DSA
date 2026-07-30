#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace  std;

bool validParantheses(string s){
    stack<char> container;

    for(char i : s){
        if(i == '(' || i == '{' || i == '['){
            container.push(i);
        }else{
            if(i == ')' && !container.empty() && container.top() == '('){//? corner case if stack is empty when only closing or opening < closing then stack is empty 
                container.pop();
            }else if(i == '}' && !container.empty() && container.top() == '{'){
                container.pop();
            }else if(i == ']' && !container.empty() && container.top() == '['){
                container.pop();
            }else{
                return false;
            }
        }
    }

    return container.size() == 0;
}

int main () {
    string s = "()";
    cout << validParantheses(s) << endl;
    return 0;
}