class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {{'}','{'}, {']', '['}, {')', '('}};
        stack<char> sta;
        for(char x : s){
            if(x == '(' || x == '[' || x == '{') sta.push(x);
            else{
                if(sta.empty()) return false;
                if(sta.top() != m[x]) return false;
                sta.pop();
            }
        }
        return (sta.size() == 0);
    }
};