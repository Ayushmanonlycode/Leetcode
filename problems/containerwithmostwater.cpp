class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max_area=0;
        while(left<right)
        {
            int min_height=min(height[left],height[right]);
            int current_area=min_height*(right-left);
            if(current_area> max_area) max_area=current_area;
            if(height[left]<height[right])
            {
                left++;

            }
            else right--;
  


        }
        return max_area;
    }
};