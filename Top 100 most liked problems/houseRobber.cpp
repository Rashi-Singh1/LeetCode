//O(N) time and O(1) solution
typedef long long int ll;
class Solution {
public:
    int rob(vector<int>& A) {
        ll odd = 0, even = 0;
        for(int i = 0 ; i < A.size(); i++){
            if(i&1) odd = max(even, odd + (ll)A[i]);            //odd
            else even = max(odd, even + (ll)A[i]);              //even
        }
        return (int)max(odd, even);
    }
};