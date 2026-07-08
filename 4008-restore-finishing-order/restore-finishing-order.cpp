class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        unordered_set<int>list(friends.begin(),friends.end());

        for(int o:order){
            if(list.count(o)){
                ans.push_back(o);
            }
        }
        return ans;
    }
};