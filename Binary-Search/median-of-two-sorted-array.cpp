#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

double median(vector<int> &A, vector<int> &B){
    int n1 = A.size(), n2 = B.size();
    int totalSize = n1 + n2;
    int half = totalSize / 2;
    int left{0}, right{n1};
    if (n1 > n2){
        return median(B, A);
    }
    while(1){
        int i = left + (right - left) / 2;
        int j = half - i;

        double Aleft{0}, Aright{0}, Bleft{0}, Bright{0};

        //Aleft
        if(i-1 >= 0) Aleft = A[i - 1];
        else Aleft = INT_MIN;
        //Aright
        if(i < n1) Aright = A[i];
        else Aright = INT_MAX;

        //Bleft
        if(j-1 >= 0) Bleft = B[j - 1];
        else Bleft = INT_MIN;
        //Bright
        if(j < n2) Bright = B[j];
        else Bright = INT_MAX;

        if(Aleft <= Bright && Bleft <= Aright){
            if (totalSize % 2)
            {
                return min(Aright, Bright);
            }
            else
            {
                double mid = (max(Aleft, Bleft) + min(Aright, Bright)) / 2;
                return mid;
            }
        }else if( Aleft > Bright){
            right = i - 1;
        }else{
            left = i + 1;
        }
    }
    return {-0.1};
}

int main () {
    vector<int> A = {1,2,3,4};
    vector<int> B = {1};
    cout << median(A, B)<<endl;
    return 0;
}