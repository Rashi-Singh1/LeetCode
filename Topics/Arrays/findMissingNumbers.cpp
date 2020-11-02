typedef long long int ll;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& A) {
        vector<int> ans;
        ll n = A.size();
        for(int i = 0 ; i < A.size(); i++){
            ll cur = ((ll)A[i]%(n+1ll)) - 1ll;
            ll next = ((ll)A[cur] % (n+1ll));
            A[cur] = (int) (next + (n+1ll));
        }
        for(int i = 0 ; i < A.size(); i++){
            A[i]/=(n+1ll);
            if(A[i] == 0) ans.push_back(i+1);
        }
        return ans;
    }
};