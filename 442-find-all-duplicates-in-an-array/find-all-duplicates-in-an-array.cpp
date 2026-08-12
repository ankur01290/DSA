class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>unset;
        for(int i=0;i<nums.size();i++){
            if(unset.count(nums[i])==false){
                unset.insert(nums[i]);
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};