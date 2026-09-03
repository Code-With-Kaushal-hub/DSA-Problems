class Solution {
public:

    bool sudokusolver(vector<vector<char>>& board,int row,int col){
        if(row==9){
            
            return true;
        }
        int nextrow=row;
        int nextcol=col+1;
        if(col+1==9){
            nextrow=row+1;
            nextcol=0;
        }
        if(board[row][col]!='.'){
            return sudokusolver(board,nextrow,nextcol);
        }
        for(int val=1;val<=9;val++){
            if(issafe(board,row,col,val)){
                board[row][col] = char('0' + val);
                if(sudokusolver(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col]='.';
            }


        }
        return false;


    }
    bool issafe(vector<vector<char>>& board,int row,int col,int digit){
        for(int i=0;i<=8;i++){
            if(board[i][col]==char('0' + digit)){
                return false;
            }
        
        }
        for(int j=0;j<=8;j++){
            if(board[row][j]==char('0' + digit)){
                return false;
            }
            
        }
        int newrow=(row/3)*3;
        int newcol=(col/3)*3;
        for(int i=newrow;i<=newrow+2;i++){
            for(int j=newcol;j<=newcol+2;j++){
                if(board[i][j]==char('0' + digit)){
                return false;
            }
            

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokusolver(board,0,0);
        
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