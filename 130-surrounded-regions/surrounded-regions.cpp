class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& visit,vector<vector<char>>& board, int delrow[],int delcol[],int n,int m){
        visit[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !visit[nrow][ncol]){
                dfs(nrow,ncol,visit,board,delrow,delcol,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visit(n,vector<int >(m,0));
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        for(int i=0;i<n;i++){
            //vertical first full col;
            if(board[i][0]=='O' && !visit[i][0]){
                dfs(i, 0,visit,board,delrow,delcol,n,m);
            }

            //vertical last full col;
            if(board[i][m-1]=='O'&& !visit[i][m-1]){
                    dfs(i,m-1,visit,board,delrow,delcol,n,m);
            }
        }
        
        for(int i=0;i<m;i++){
            
                
            
        }
        
        for(int i=0;i<m;i++){
            // horizontal first row;
            if(board[0][i]=='O'&& !visit[0][i]){
                dfs(0,i,visit,board,delrow,delcol,n,m);
            }

            // horizontal last row;
            if(board[n-1][i]=='O'&& !visit[n-1][i]){
                dfs(n-1,i,visit,board,delrow,delcol,n,m);
                
            }
        }
        // horizontal last row;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        

    }
};