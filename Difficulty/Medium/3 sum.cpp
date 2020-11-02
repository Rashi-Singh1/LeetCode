//solution using map
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        map<pair<int,int>,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                int start = i + 1;
                int end = nums.size()-1;
                while(start < end){
                    if(nums[i] + nums[start] + nums[end] == 0){
                        if(mp.count(make_pair(nums[i],nums[start])) == 0){
                            mp[make_pair(nums[i],nums[start])] = nums[end];
                            vector<int> temp = {nums[i],nums[start],nums[end]};
                            ans.push_back(temp);
                        }
                        int old_end = end, old_start = start;
                        do{
                            if(nums[old_end] == nums[end]) end--;
                            if(nums[old_start] == nums[start]) start++;
                        }
                        while(start < end && nums[start] == nums[old_start] && nums[end] == nums[old_end]);
                    }else if(nums[start] + nums[end] + nums[i] < 0) start++;
                    else end--;
                }
            }
        }
        return ans;
    }
};

//solution without using map
class Solution {
public:
    void double_sum(vector<vector<int> >&ans, vector<int>& nums, int index){
        int start = index + 1;
        int end = nums.size()-1;
        while(start < end){
            // if(nums[index] == -2) cout<<index<<" "<<start<<" "<<end<<" "<<nums[start]<<" "<<nums[end]<<endl;
            if(nums[start] + nums[end] + nums[index] == 0) {
                vector<int> temp;
                temp.push_back(nums[index]);
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                ans.push_back(temp);
                int old_start = start;
                int old_end = end;
                do{
                    if(nums[old_start] == nums[start]) start++;
                    if(nums[old_end] == nums[end]) end--;
                }while(start < end && (nums[start] == nums[old_start] || nums[end] == nums[old_end]));
            }
            else if(nums[start] + nums[end] + nums[index] < 0) start++;
            else end--;
        }
    }
    
    bool equal(vector<int>& a, vector<int>& b){
        for(int i = 0; i < a.size(); i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        // for(auto x : nums) cout<<x<<" "; cout<<endl;
        for(int i = 0; i < nums.size(); i++){
            double_sum(ans, nums, i);
        }
        int old_size = ans.size();
        sort(ans.begin(),ans.end(),[](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) {
            if(a[1] == b[1])
                return a[2] < b[2];
                else return a[1] < b[1];
            }
            else return a[0] < b[0];
        });
        if(ans.size() > 0){
            auto new_size = std::unique(ans.begin(),ans.end());
            ans.resize(std::distance(ans.begin(),new_size));
        }
        return ans;
    }
};