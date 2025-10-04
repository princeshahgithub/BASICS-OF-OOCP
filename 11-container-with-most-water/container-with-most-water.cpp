class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max_water = 0;
        while(start < end) {
            int curr_cont = min(height[start], height[end]) * (end - start);
            max_water = max(max_water, curr_cont);
            if(height[start] < height[end]) start++;
            else end--;
        }
        return max_water;
    }
};