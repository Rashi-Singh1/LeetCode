class Solution {
public:
    void three_sum(int index, vector<int>& nums, vector<vector<int> >&ans, int target ) {
        map<pair<int,int>,int> mp;
        for(int i = index + 1; i < nums.size(); i++){
            int start = i + 1;
            int end = nums.size()-1;
            while(start < end){
                if(nums[i] + nums[start] + nums[end] == target){
                    if(mp.count(make_pair(nums[i],nums[start])) == 0){
                        mp[make_pair(nums[i],nums[start])] = nums[end];
                        vector<int> temp = {nums[index],nums[i],nums[start],nums[end]};
                        ans.push_back(temp);
                    }
                    int old_end = end, old_start = start;
                    do{
                        if(nums[old_end] == nums[end]) end--;
                        if(nums[old_start] == nums[start]) start++;
                    }
                    while(start < end && nums[start] == nums[old_start] && nums[end] == nums[old_end]);
                }else if(nums[start] + nums[end] + nums[i] < target) start++;
                else end--;
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans; 
        for(int i = 0; i < nums.size();){
            three_sum(i, nums, ans, target-nums[i]);
            int old_i = i;
            do{
                i++;
            }while(i < nums.size() && nums[old_i] == nums[i]);
        }
        return ans;
    }
};