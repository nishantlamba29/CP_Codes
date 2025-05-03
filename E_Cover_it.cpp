#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 200005;
int n, m, a, b, color[N+1];
vector<int> adj[N+1];

void dfs(int node = 1){
    for(auto &j : adj[node]){
        if(color[j] == -1){
            color[j] = !color[node];
            dfs(j);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        color[i] = -1;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    color[1] = 1;
    dfs();
    vector<int> ans, ans2;
    int cnt = 0, cnt2 = 0;
    for(int i=1;i<=n;i++){
        if(color[i] == 0){
            cnt++;
            ans.push_back(i);
        }
        else{
            cnt2++;
            ans2.push_back(i);
        }
    }
    if(cnt <= n/2){
    cout<<cnt<<"\n";
    for(auto i : ans) cout<<i<<" ";}
    else{
        cout<<cnt2<<"\n";
        for(auto i : ans2) cout<<i<<" ";
    }
    cout<<"\n";

    

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}