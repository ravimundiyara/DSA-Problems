class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int row, int col, char d){
        for(int i=0;i<9;i++){ 
            if(board[i][col]==d){  //sari rows check krega ki kahi element pahle se h to nhi 
                return false;
            }
            if(board[row][i]==d){  // sare columns check krega ki kahi element pahle se h to nhi 
                return false;
            }
        }
        int new_i=row/3 *3;   // 3*3 ki grid mai check krega ki kahi element pahle se present to nhi h
        int new_j=col/3 *3;
        for(int k=0;k<3;k++){
            for(int l=0; l<3;l++){
                if(board[new_i +k][new_j +l]==d){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){     // rows ko traverse krega
            for(int j=0;j<9;j++){  // columns ko traverse krega
                if(board[i][j]=='.'){
                    for(char d='1';d<='9'; d++){
                        if(isvalid(board, i, j, d)){ //ye function check krega ki uss current row, column and grid mai element present to nhi h
                            board[i][j]=d;  // do
                            if(solve(board)==true){ //explore
                                return true;
                            }
                            board[i][j]='.';  //undo 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); //function call kra
    }
};