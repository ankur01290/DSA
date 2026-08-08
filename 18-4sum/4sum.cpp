class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                int k=nums.size()-1;
                int l=j+1;
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                while(l<k){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        
                        while(nums[k]==nums[k-1] && k>l ){
                            k--;
                        }
                        while(l<k && nums[l+1]==nums[l]){
                            l++;
                        }
                        k--;
                        l++;
                    }
                    else if(sum>target){
                        k--;
                        
                    }
                    else{
                        l++;
                       
                    }
                }
            }
        }
        return ans;
    }
};