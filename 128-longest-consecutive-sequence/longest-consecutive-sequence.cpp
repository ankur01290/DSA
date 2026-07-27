class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1, maxi=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<nums.size();i++){

            if(nums[i-1]+1==nums[i]){
                count++;
                maxi=max(count,maxi);
            }

            else if(nums[i-1]==nums[i]){
                continue;
            }
            else{
                count=1;
            }
        }
        return maxi;
    }
};