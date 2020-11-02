class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        int ans = 1;
        unordered_map<char, int> sta;
        int start = 0;
        sta.insert(make_pair(s[0],0));
        for(int i = 1; i < s.size(); i++){
            if(sta.count(s[i])){
                ans = max(ans,i-start);
                start = max(start,sta[s[i]] + 1);
            }
            cout<<start<<i<<endl;
            ans = max(ans,i-start + 1);
            sta[s[i]] = i;
        }
        return ans;
    }
};