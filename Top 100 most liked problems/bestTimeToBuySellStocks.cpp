//this is diff as max one transaction is allowed
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if(A.size() < 2) return 0;
        int ans = 0, minn = A[0];
        for(int i = 1; i < A.size(); i++){
            if(A[i] > minn) ans = max(ans, A[i]-minn);
            else minn = A[i];
        }
        return ans;
    }
};