class Solution {
public:
    
    int find_volume(int left, int right, vector<int>& height){
        return min(height[left],height[right]) * (right - left);
    }
    
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int ans = 0;
        while(start < end){
            ans = max(ans, find_volume(start, end, height));
            if(height[start] < height[end]) start++;
            else end--;
        }
        return ans;
    }
};