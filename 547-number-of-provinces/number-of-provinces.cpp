class Solution {
private:
    void dfs(int node,vector<int>adjl[],vector<bool>&vist){
        vist[node]=true;
        for(auto it:adjl[node]){
            if(!vist[it]){
                dfs(it,adjl,vist);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>adjl[v];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        vector<bool>vist(v,false);
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vist[i]){
                cnt++;
                dfs(i,adjl,vist);
            }
        }
        return cnt;
    }
};