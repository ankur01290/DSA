class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int >mpp;
        for(int i=0;i<nums.size();i++){
            int compli=target-nums[i];
            if(mpp.count(compli)){
                return {mpp[compli],i};
            }
            mpp[nums[i]]=i;
        }
        return {0,0};
    }
};