#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> max_jump(n+1);
    for(int i=1;i<=n;i++) max_jump[i] = i+1;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        max_jump[u] = max(max_jump[u], v);
    }
    vector<int> time(n+1, inf);
    time[1] = 0;
    for(int i=1;i<=n;i++){
        time[i] = min(time[i], time[i-1] + 1);
        for(auto &j : adj[i]) time[j] = min(time[j], time[i] + 1);
    }
    int maxi = 0;
    for(int i=1;i<n;i++){
        cout<<(i >= maxi) ? 1 : 0;
        maxi = max(maxi, max_jump[i] - time[i] - 1);
    }
    cout<<"\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
    return 0;
}