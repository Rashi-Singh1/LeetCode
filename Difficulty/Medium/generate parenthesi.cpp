#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(string cur, vector<string>& ans, int n, vector<int>& count){
    if(cur.size() == 2*n){
        ans.push_back(cur);
        return;
    }
    if(cur.size() > 2*n) return;
    if(count[0] > 0){
        cur.push_back('(');
        count[0]--;
        solve(cur,ans,n,count);
    }
    if(count[1] > 0 && count[0] < count[1]){
        count[1]--;
        cur.push_back(')');
        solve(cur,ans,n,count);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    vector<int> count = {n,n};
    solve("",ans,n,count);
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    vector<string> ans;
    int n;
    cin>>n;
    ans = generateParenthesis(n);
    for(auto x : ans){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}
