class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int valid=0;
        
        for(int i=0;i<nums.size();i++){
            int x_even=0;
            int y_odd=0;
            for(int j=i;j<nums.size();j++){
                
                if(nums[j]%2==0){
                    x_even++;
                }
                else{
                    y_odd++;
                }
                if(y_odd>0 && x_even*b<=a*y_odd){
                    valid++;
                }
            }
        }
        return valid;
    }
};