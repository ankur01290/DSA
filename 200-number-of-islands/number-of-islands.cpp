class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visit,int n,int m){
        queue<pair<int,int>>q;
        visit[row][col]=1;
        q.push({row,col});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visit[nrow][ncol]){
                    visit[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visit[i][j]){
                    count++;
                    bfs(i,j,grid,visit,n,m);
                }   
            }
        }
        return count;
    }
};