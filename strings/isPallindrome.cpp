#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace  std;

/*
bool validPallindrome(string s){
    int left = 0, right = s.length() - 1;

    while(left < right){

        if(!isalnum(s[left])){
            left++;
            continue;
        }

        if(!isalnum(s[right])){
            right--;
            continue;
        }

        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }

    return true;
}
*/

bool validPallindrome(string s){
    int left = 0, right = s.length() - 1;

    while(left <= right){

        while(left < right && !isalnum(s[left])){
            left++;
        }

        while(left < right && !isalnum(s[right])){
            right--;
        }

        if(left >= right)
            return true;

        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main () {
    string s = "A man, a plan, a canal: Panama";
    cout << validPallindrome(s)<<endl;
    return 0;
}