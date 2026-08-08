class Solution {
public:
    int maxArea(vector<int>& height) {
        int mini_height=0, distance=0, max_area=0;
        //left and right *using two pointer approach;
        int left=0,right=height.size()-1;
        while(left<=right){
            mini_height=min(height[left],height[right]);
            distance=right-left;
            int area=mini_height*distance;
            max_area=max(area,max_area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return max_area;
    }
};