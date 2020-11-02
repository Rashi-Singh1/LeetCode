class Solution {
public:
    void solve(string digits, vector<string>& ans, int index, string cur_string, string* val){
        if(index == digits.size()){
            ans.push_back(cur_string);
            return;
        }
        int string_index = (int)(digits[index]-'0') - 2;
        for(int i = 0; i < val[string_index].size(); i++){
            cur_string.push_back(val[string_index][i]);
            solve(digits,ans,index + 1, cur_string,val);
            cur_string.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string val[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size() == 0) return ans;
        solve(digits,ans,0,"", val);
        return ans;
    }
};