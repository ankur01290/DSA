class Solution {
private:
    bool dfs(int node,int parent,vector<int>&visit,vector<vector<int>>& adj){
        visit[node]=1;
        for(auto adjs:adj[node]){
            if(visit[adjs]==0){
                if(dfs(adjs,node,visit,adj)==true) 
                    return true;
                
            }
            else if(visit[adjs]==1){
                return true;
            }
        }
        visit[node]=2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> visit(numCourses, 0);
        for(int i=0;i<numCourses;i++){    
            if(visit[i]==0){
                if(dfs(i,-1,visit,adj))
                    return false;
            }
        }
        return true;

    }
};