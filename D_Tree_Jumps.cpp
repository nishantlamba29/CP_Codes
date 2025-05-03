#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 300000;
const int mod = 998244353;
int n, depth[N+1], dp[N+1];
vector<int> tree[N+1], mp[N+1];

void dfs(int node = 1, int p = -1, int d = 0){
    depth[node] = d;
    mp[d].push_back(node);
    for(auto &j : tree[node]){
        dfs(j, node, d+1);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<=n;i++){
        tree[i].clear();
        mp[i].clear();
        depth[i] = 0;
        dp[i] = 0;
    }
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        tree[p].push_back(i);
    }
    
    dfs();

    int prev = 0;
    for(int ht=n-1;ht>=1;ht--){
        if(mp[ht].empty()) continue;
        int curr = 0;
        for(auto &ele : mp[ht]){
            dp[ele] = 1;
            int temp = 0;
            for(auto &j : tree[ele]){
                temp = (temp + dp[j]) % mod;
            }
            dp[ele] = (dp[ele] + prev - temp + mod) % mod;
            curr = (curr + dp[ele]) % mod;
        }
        prev = curr;
    }

    cout<<(prev+1) % mod<<"\n";

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin>>tt;
    while(tt--) solve();

    return 0;
}