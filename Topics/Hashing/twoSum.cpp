class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> s;
        for(int i = 0; i < A.size(); i++){
            if(s.count(target-A[i])> 0) return {s[target-A[i]], i};
            s[A[i]] = i;
        }
        return {};
    }
};