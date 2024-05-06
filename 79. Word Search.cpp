class Solution {
public:
    bool check(int ind,int i, int j, vector<vector<char>>& board, string word){
        int n=board.size();
        int m=board[0].size();
        if(ind==word.size()){
            return true;
        }
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[ind]){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='$';
        bool found=check(ind+1,i+1,j,board,word)||
                   check(ind+1,i,j+1,board,word)||
                   check(ind+1,i-1,j,board,word)||
                   check(ind+1,i,j-1,board,word);

        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && check(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
