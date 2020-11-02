typedef long long int ll;
class Solution {
public:
    int maxSubArray(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll sum = 0, ans = LLONG_MIN;
        for(int i = 0 ; i < A.size(); i++){
            sum += (ll)A[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};