class Solution {
private:
    bool dfscheck(int node,vector<vector<int>>&prerequistes,vector<int>&visited,vector<int>&pathVisited,vector<int>&ans){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto it:prerequistes[node]){
            if(!visited[it]){
                if(dfscheck(it,prerequistes,visited,pathVisited,ans))
                    return true;
            }
            else if(pathVisited[it]==true){
                return true;
            }
        }
        pathVisited[node]=0;
        ans.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int>ans;
        vector<int>pathVisited(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfscheck(i,adj,visited,pathVisited,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};