class Solution {
public:
    vector<vector<string>> g;
    
    bool issafe(vector<string>& board, int row, int col, int n) {
        // check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // check upper-left diagonal
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // check upper-right diagonal
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void nqueens(vector<string>& board, int row, int n) {
        if (row == n) {  // base case: placed queens in all rows
            g.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (issafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueens(board, row+1, n);
                board[row][j] = '.';  // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        nqueens(board, 0, n);
        return g;
    }
};