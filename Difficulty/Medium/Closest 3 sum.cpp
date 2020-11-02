class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long int diff = INT_MAX;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end){
                long long int sum = nums[i] + nums[start] + nums[end];
                if(llabs(sum-(long long int)target) < diff){
                    diff = llabs(sum-(long long int)target);
                    ans = (int)sum;
                    if(diff == 0) return (int)ans;
                }
                if(sum > target) end--;
                else start++;
            }
        }
        return ans;
    }
};