class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>check;
        set<int>ans;
        vector<int>ans1;
        for(auto n:nums1){
            check.insert(n);
        }
        for(int i=0;i<nums2.size();i++){
            if(check.count(nums2[i])){
                ans.insert(nums2[i]);
            }   
        }
        for(auto n:ans){
            ans1.push_back(n);
        }
        return ans1;
    }
};