class Solution { 
public: 
 
    bool sudokusolver(vector<vector<char>>& board, int row, int col) { 
        
        for(int i = 0; i < 9; i++) { 
            for(int j = 0; j < 9; j++) { 
                
                if(board[i][j] == '.') { 
                    
                    for(int val = 1; val <= 9; val++) { 
                        
                        if(issafe(board, i, j, val)) { 
                            
                            board[i][j] = char('0' + val); 
                            
                            if(sudokusolver(board, i, j + 1)) { 
                                return true; 
                            } 
                            else { 
                                board[i][j] = '.'; 
                            } 
                        } 
                    } 
                    
                    return false; 
                } 
            } 
        } 
        
        return true; 
    } 
    
    bool issafe(vector<vector<char>>& board, int row, int col, int digit) { 
        
        for(int i = 0; i <= 8; i++) { 
            
            if(board[i][col] == char('0' + digit)) { 
                return false; 
            } 
            
            if(board[row][i] == char('0' + digit)) { 
                return false; 
            } 
 
            if(board[3 * (row / 3) + i / 3]
                    [3 * (col / 3) + i % 3] == char('0' + digit)) { 
                return false; 
            } 
        } 
        
        return true; 
    } 
    
    void solveSudoku(vector<vector<char>>& board) { 
        sudokusolver(board, 0, 0); 
    } 
};
/*1. Event Propagation — Bubbling & Capturing
2. prototype in JS
3. promises
4. callback &callback hell
5.Debouring & Trottling
6.Basics of API,s
7.Execution Context & Call Stack
8. Local Storage vs Session Storage*/