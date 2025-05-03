#include "bits/stdc++.h"
using namespace std;

#define int long long

const int N = 2e5;
int n, dp[N+1], vis[N+1], vis2[N+1], mark[N+1], val[N+1];;
vector<int> adj[N+1], radj[N+1], tree[N+1];
stack<int> st;

void dfs(int node){
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(!vis[j]) dfs(j);
    }
    st.push(node);
}

void dfs2(int node, int k, int &cnt){
    vis2[node] = 1;
    mark[node] = k;
    cnt++;
    for(auto &j : radj[node]){
        if(!vis2[j]) dfs2(j, k, cnt);
    }
}

int dfs3(int node){
    int ans = 0;
    for(auto &j : tree[node]){
        ans = max(ans, dfs3(j));
    }
    return dp[node] = ans + val[node];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i + 1 == x) continue;
        adj[i+1].push_back(x);
        radj[x].push_back(i+1);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    int k = 1;
    while(st.size()){
        int node =st.top();
        st.pop();
        if(vis2[node]) continue;
        int cnt = 0;
        dfs2(node, k, cnt);
        val[k] = cnt;
        k++;
    }

    set<pair<int,int>> S;
    vector<int> indegree(k);
    for(int i=1;i<=n;i++){
        for(auto &j : adj[i]){
            if(S.find({mark[i], mark[j]}) == S.end() && mark[i] != mark[j]){
                tree[mark[i]].push_back(mark[j]);
                indegree[mark[j]]++;
                S.insert({mark[i], mark[j]});
            }
        }
    }

    for(int i=1;i<k;i++){
        if(indegree[i] == 0) dfs3(i);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += dp[mark[i]];
    }
    cout<<ans;

    return 0;
}