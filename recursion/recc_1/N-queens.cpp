#include <iostream>
#include <vector>

using namespace  std;

bool isSafe(vector<vector<bool>>& board, int n, int r, int c){
    //upper col
    for (int i = r - 1; i >= 0; i--){
        if(board[i][c]) return false;
    }

    //upper-left-diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]) return false;
    }

    // upper-right-diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++){
        if(board[i][j]) return false;
    }

    return true;
}

void printBoard(vector<vector<string>>& board){
    for(auto i : board){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl;
    return;
}
static int count = 0;
void placeNQueens(vector<vector<bool>>& board, int n, int r, vector<vector<string>>& soln){
    if(r == n){
        printBoard(soln);
        count++;
        return;
    }
    for (int c = 0; c < n; c++){
        if(isSafe(board,n,r,c)){
            board[r][c] = true;
            soln[r][c] = "Q";
            placeNQueens(board, n, r + 1, soln);
            board[r][c] = false;
            soln[r][c] = ".";
        }
    }
}

int main () {
    int n = 8;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<vector<string>> soln(n, vector<string>(n,"."));

    placeNQueens(board, n, 0, soln);
    cout << count << endl;

    return 0;
}