class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visit,int delrow[],int delcol[],int n,int m){
        visit[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visit[nrow][ncol]){
                dfs(nrow,ncol,grid,visit,delrow,delcol,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        //
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visit[i][0]){
                dfs(i,0,grid,visit,delrow,delcol,n,m);
            }
            if(grid[i][m-1] && !visit[i][m-1]){
                dfs(i,m-1,grid,visit,delrow,delcol,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !visit[0][i]){
                dfs(0,i,grid,visit,delrow,delcol,n,m);
            }
            if(grid[n-1][i] && !visit[n-1][i]){
                dfs(n-1,i,grid,visit,delrow,delcol,n,m);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j]){
                    count++;
                }
            }
        }
        return count;

    }
};