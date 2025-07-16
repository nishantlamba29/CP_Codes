#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int n, k;
vector<int> adj[N];
int sz[N], par2[N];
bool mark[N];

void dfs_sz(int node, int p) {
    sz[node] = 1;   
    for(auto &j : adj[node]) {
        if(j != p && !mark[j]) {
            dfs_sz(j, node);
            sz[node] += sz[j];
        }
    }
}

int dfs2(int node, int p, int total) { // return centroid
    for(auto &j : adj[node]) {
        if(j != p && !mark[j] && sz[j] > total / 2) {
            return dfs2(j, node, total);
        }
    }
    return node;
}

void Decompose(int node, int p) {
    dfs_sz(node, p);
    int cen = dfs2(node, p, sz[node]);
    mark[cen] = 1;
    par2[cen] = p;
    for(auto &j : adj[cen]) {
        if(!mark[j]) {
            Decompose(j, cen);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i <= n; i++) {
        mark[i] = false;
        sz[i] = 0;
        par2[i] = -1;
    }

    Decompose(1, -1);
    

    return 0;
}