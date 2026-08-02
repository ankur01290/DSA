class Solution {
private:
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int visit[n][m];
        //vector<vector<int>>ans=grid;
        queue<pair<pair<int,int>,int>>q;
        int count=0 ,count1=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visit[i][j]=2;
                    
                }
                else{
                    visit[i][j]=0;
                }
                if(grid[i][j]==1) count++;
            }
        }
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        int tm=0;
        //pair
        while(!q.empty()){
            int n=grid.size();
            int m=grid[0].size();
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visit[nrow][ncol]!=2){
                    q.push({{nrow,ncol},tm+1});
                    visit[nrow][ncol]=2;
                    
                    count1++;    
                }
            }
        }

        if(count!=count1){
            return -1;
        }

        // for(int i=0;i<dup.size();i++){
        //     for(int j=0;j<dup[0].size();j++){
        //         if(dup[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        return tm;
    }
};