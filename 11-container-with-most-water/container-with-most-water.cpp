class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0,curr_area=0, length1=0, length2=0;
        int left=0,right=height.size()-1;
        while(left<right){
            length1=max(length1,height[left]);
            length2=max(length2,height[right]);
            int mini=min(length1,length2);
            int width=right-left;
            curr_area=width*mini;
            area=max(curr_area,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};