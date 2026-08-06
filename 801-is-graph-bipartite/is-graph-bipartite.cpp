class Solution {
private:
    bool bfscheck(int start,int n,vector<vector<int>>& adj,vector<int>&color){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
            
        }
        return true;
    }
    bool dfscheck(int start,int col,vector<vector<int>>& adj,vector<int>&color){
        color[start]=col;
        for(auto it:adj[start]){
            if(color[it]==-1){
                if(!dfscheck(it,!col,adj,color)){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                // if(!bfscheck(i,n,graph,color)){
                //     return false;
                // }
                if(!dfscheck(i,0,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }

};