class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        string ans;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            int e = i<(s.size()-i) ? i : s.size()-i;
            bool type1 = true;
            bool type2 = true;
            int old_end = e;
            for(int j = 1; j <= old_end; j++ ){
                if(type1 == true){
                    if(s[i-j] != s[i+j]) {
                         if(end-start + 1 < (2*j)-1) {
                            start = i-j+1;
                            end = i+j-1;
                        }
                        type1 = false;
                    }
                    else{
                        if(end-start + 1 < (2*j)+1) {
                            start = i-j;
                            end = i+j;
                        }
                    }
                }
                if(type2 == true){
                    if(s[i-j]!=s[i+j-1]){
                        if(end-start + 1 < (2*j)-2) {
                            start = i-j+1;
                            end = i+j-2;
                        }
                        type2 = false;
                    } 
                    else{
                         if(end-start + 1 < (2*j)) {
                            start = i-j;
                            end = i+j-1;
                        }
                    }
                }
                if(type1 || type2) continue;
                else break;
            }
        }
        if(end >= start)return s.substr(start,end-start+1);
        return ans;
    }
};