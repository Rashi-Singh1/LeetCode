//way 1 : fibonacci
typedef long long int ll;
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        n-=2;
        ll a = 1, b = 2, c;
        while(n > 0){
            c = a+b;
            a = b;
            b = c;
            n--;
        }
        return (int)c;
    }
};

//way 2: DP
class Solution {
private:
    int solve(vector<int>& ans, int n){
        if(n < 3) return n;
        if(ans[n] != -1) return ans[n];
        ans[n] = solve(ans, n-1) + solve(ans, n-2);
        return ans[n];
    }
public:
    int climbStairs(int n) {
        vector<int> ans(n+1, -1);
        return solve(ans, n);
    }
};