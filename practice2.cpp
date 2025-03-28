#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int rec(int n, int k, vector<int>& dp){
    if(n <= 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ff = 0;
    if(n-k >= 0){
        ff = rec(n-k, k, dp) + 1;
    }
    int ss = 1 +rec(n-1, k, dp);

    return dp[n] = ff + ss;
}
vector<int> getNumStrings(int k, vector<vector<int>> query){
    int mx = 0;
    for(auto i : query){
        mx = max(mx, i[1]);
    }
    vector<int> res;
    vector<int> dp(mx+1,-1);
    int ans = rec(mx, k, dp);
    for(auto i : query){
        int l = rec( i[0]-1, k, dp) ;
        int r = rec( i[1], k, dp) ;
        res.push_back(r-l);
    }
    return res;

}
int main(){


    vector<vector<int>> q = {{1,3}};
    int k = 3;

    vector<int> res = getNumStrings(k, q);

    for(auto i : res){
        cout<<i<<" ";

    }
    cout<<"\n";
    
}