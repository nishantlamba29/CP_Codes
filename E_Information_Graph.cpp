#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 1e5;
int n, m, par[N+1][20], depth[N+1], pr[N+1], sz[N+1];
vector<int> adj[N+1], ans;
vector<pair<int,int>> ques[N+1];
vector<vector<int>> query;


void dfs(int node = 1, int p = 1, int d = 0){
    par[node][0] = p;
    depth[node] = d;
    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto &j : adj[node]){
        dfs(j, node, d + 1);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int i=19;i>=0;i--){
        if(diff >> i & 1){
            u = par[u][i];
        }
    }

    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int find(int x){
    return x == pr[x] ? x : find(pr[x]);
}
bool merge(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return 0;
    if (sz[p1] < sz[p2]) swap(p1, p2);
    pr[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int cnt = 0;
    int idx = 1;
    vector<int> indegree(n+1, 0);
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t == 1){
            int x,y;
            cin>>x>>y;
            adj[y].push_back(x);
            indegree[x]++;
            query.push_back({t, x, y});
        }
        else if(t == 2){
            int x;
            cin>>x;
            query.push_back({t, x});
        }
        else{
            int emp, doc;
            cin>>emp>>doc;
            query.push_back({t, emp, doc});
            ques[doc].push_back({emp, cnt});
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0) dfs(i);
    }

    ans.resize(cnt);
    for(int i=0;i<=n;i++){
        pr[i] = i;
        sz[i] = 1;
    }

    for(auto q : query){
        if(q[0] == 1){
            merge(q[1], q[2]);
        }
        else if(q[0] == 2){
            int emp1 = q[1];
            for(auto &[emp2, index] : ques[idx]){
                int par1 = find(emp1);
                int par2 = find(emp2);
                if(par1 != par2){
                    ans[index] = 0;
                    continue;
                }
                int ut = lca(emp1, emp2);
                if(ut == emp2) ans[index] = 1;
                else ans[index] = 0;
            }
            idx++;
        }
    }

    for(int i=0;i<cnt;i++){
        if(ans[i]) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}