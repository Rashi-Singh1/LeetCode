class Solution {
public:
    string convert(string s, int row) {
        if(s.size() < 3 || row == 1) return s;
        string ans;
        for(int i = 0; i < row; i++){
            int jump = (row - i - 1)*2-1;           //jump is the skipping of valley
            for(int j = i;j < s.size();){
                if(i < row - 1) {                   //for last row, no need to skip valleys
                    ans.push_back(s[j]);
                    j+=(jump+1);                    //plus 1 bcs need to add the next element after skipping
                }
                if(i > 0){                          //for first row, no need to skip mountain peaks
                    int jump2 = (row-1)*2-1;        
                    jump2-=jump;                    //jump2 is the skipping of mountain peaks
                    if(j < s.size()) ans.push_back(s[j]);
                    j+=jump2;
                }
            }
        }
        return ans;
    }
};