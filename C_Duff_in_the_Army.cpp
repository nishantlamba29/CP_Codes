#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;
int n, m, q, u, v, a, sz[N+1], depth[N+1], par[N+1][20];
vector<int> adj[N+1], people[N+1], people_2j[N+1][20];


vector<int> merge(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else {
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        ans.push_back(a[i]);
        i++;
    }
    while(j < m){
        ans.push_back(b[j]);
        j++;
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    while(ans.size() > 10) ans.pop_back();
    return ans;
}


void dfs(int node = 1, int p = -1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    if(p != -1)
        people_2j[node][0] = merge(people[node], people[p]);
    else
        people_2j[node][0] = people[node];

    for(int i=1;i<20;i++){
        if(par[node][i-1] != -1){
            par[node][i] = par[par[node][i-1]][i-1];
            people_2j[node][i] = merge(people_2j[node][i-1], people_2j[par[node][i-1]][i-1]);
        }
        else{
            par[node][i] = -1;
            people_2j[node][i] = people_2j[node][i-1];
        }
    }

    for(auto &j : adj[node]){
        if(j != p) {
            sz[j] += sz[node] + people[j].size();
            dfs(j, node, d + 1);
        }
    }
}

int kpar(int u, int k, vector<int> &ans){
    for(int i=19;i>=0;i--){
        if(k >> i & 1){
            ans = merge(ans, people_2j[u][i]);
            u = par[u][i];
        }
    }
    return u;
}

int lca(int u, int v, vector<int> &ans){
    if(depth[u] < depth[v]) swap(u, v);
    u = kpar(u, depth[u] - depth[v], ans);
    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            ans = merge(ans, people_2j[u][i]);
            ans = merge(ans, people_2j[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans = merge(ans, people_2j[u][0]);
    ans = merge(ans, people_2j[v][0]);
    return par[u][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=m;i++){
        cin>>u;
        people[u].push_back(i);
    }
    sz[1] = people[1].size();
    dfs();

    while(q--){
        cin>>u>>v>>a;
        if(u == v){
            int sz = people[u].size();
            cout<<min(a, sz)<<" ";
            for(int i=0;i<min(a, sz);i++) cout<<people[u][i]<<" ";
            cout<<"\n";
            continue;
        }
        vector<int> ans;
        int ut = lca(u, v, ans);

        int cnt = sz[u] + sz[v] - 2 * sz[ut] + people[ut].size();
        cout<<min(cnt , a)<<" ";
        for(int i=0;i<min(cnt, a);i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}