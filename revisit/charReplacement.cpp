#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace  std;

//? leetCode Qno. 424

int replaceChar(string s, int k){
    int n = s.size();
    unordered_map<char, int> m;
    int left = 0, right = 0;
    int window = 0, maxFreq = 0;
    for (int i = 0; i < n; i++){
        m[s[right]]++;
        maxFreq = max(maxFreq, m[s[right]]);

        //? this if cond is the key part , maxFreq tracks the max freq of a char, and we subtract that with the current window and compare it with the number of operations allowed 
        //? think of it this way if the window keeps growing and we want is maximimum number of repeating char so the max freq should be the freq of repeating char , and when that becomes false it means we are looking in a invalid window / too much operation needed to make it valid so we slide by 1 index
        if((right - left + 1) - maxFreq > k){
            m[s[left]]--;
            left++;
        }
        window = right - left + 1;
        right++;
    }
    cout << window << endl;
    return window;
}

int main () {
    string s = "AABABBAA";
    replaceChar(s,1);
    return 0;
}