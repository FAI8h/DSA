#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

//? leetCode Qno. 74

bool searchTarget(vector<vector<int>> &matrix,int tar){
    int m = matrix[0].size();
    int n = matrix.size();

    int st{0},end{(m * n) - 1};
    
    while(st <= end){
        int mid = st + (end - st) / 2;

        int row = mid / m;
        int col = mid % m;

        if(tar == matrix[row][col]){
            cout << "true" << endl;
            return true;
        }

        if(tar > matrix[row][col]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    cout << "false" << endl;
    return false;
}

int main () {
    vector<vector<int>> matrix = {
        { 1,  3,  5,  7},
        {10, 11, 16, 20}, 
        {23, 30, 34, 60}
    };

    searchTarget(matrix, 3);
    return 0;
}