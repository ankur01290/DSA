class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
    
        long long maxi=0;
        long long gcd_=0;
        int i=1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long nums1=nums[i];
                long long nums2=nums[j];
                long long int gcd2=gcd(nums1,nums2);
                gcd_=(nums1*nums2)/pow(gcd2,2);
                maxi=max(gcd_,maxi);
            }
        }
        return maxi;
    }
};