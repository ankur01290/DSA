class Solution {
private:
    bool check(int start,int n,vector<vector<int>>& adj,vector<int>&color){
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
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>color(n,-1);
        vector<vector<int>>adj(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         adj[i].push_back(adj[j]);
        //         adj[j].push_back(adj[i]);
        //     }
        // }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,n,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }

};