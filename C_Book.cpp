#include<bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> adj[n+1], in(n+1, 0), radj[n+1];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            in[x]++;
            adj[i+1].push_back(x);
            radj[x].push_back(i+1);
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    vector<int> toposort;
    while(q.size()){
        int curr = q.front();
        q.pop();
        toposort.push_back(curr);
        for(auto j : adj[curr]){
            in[j]--;
            if(in[j] == 0){
                q.push(j);
            }
        }
    }

    if(toposort.size() != n){
        cout<<-1<<"\n";
        return;
    }
 
    vector<int> dp(n+1, 1);
    int ans = 0;
    for(auto i : toposort){
        for(auto j : radj[i]){
            if(j < i) dp[i] = max(dp[i], dp[j] + 1);
            else dp[i] = max(dp[i], dp[j]);
        }
        ans = max(ans, dp[i]);
    }

    cout<<ans<<"\n";


}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tending_to_;
    cin>>tending_to_;
    while(tending_to_-->0)
    n_lamba_29();

    return 0;
}
// Nishant ...