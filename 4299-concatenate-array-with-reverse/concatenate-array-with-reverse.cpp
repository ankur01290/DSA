class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        //int size=nums.size()*2;
        for(int i=nums.size()-1;i>=0;i--){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};