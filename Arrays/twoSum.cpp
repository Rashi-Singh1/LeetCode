class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> name;
        for(int i = 0;i<nums.size();i++)
        {
            if(name.count(target-nums[i]) > 0){
                ans.push_back(name[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            name.insert(make_pair(nums[i],i));
        }
        return ans;
    }
};
