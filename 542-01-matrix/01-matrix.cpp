class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>mat1=mat;
        queue<pair<int,int>>q;
        vector<vector<int>>visit(n,vector<int>(m,-1));
        //int visit[m][n]={-1};
        //for cantaining all the 1's;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visit[i][j]=0;
                }
            }
        }
        int dlrow[]={-1,0,+1,0};
        int dlcol[]={0,+1,0,-1};
        //------------------
        //int visit[n][m]={0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dlrow[i];
                int ncol=c+dlcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visit[nrow][ncol]==-1){
                    visit[nrow][ncol]=visit[r][c]+1;
                    q.push({nrow,ncol});
                }
            }

        }
        return visit;
    }
};