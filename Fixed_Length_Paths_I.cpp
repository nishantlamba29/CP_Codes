#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int mark[N], sz[N];
int n, k;

int dfs_sz(int node, int p) {
    int curr_sz = 1;
    for(auto &j : adj[node]) {
        if(j != p && !mark[j]) {
            curr_sz += dfs_sz(j, node);
        }
    }
    return sz[node] = curr_sz;
}

int get_centroid(int node, int p, int curr_sz) {
    for(auto j : adj[node]) {
        if(j != p && !mark[j] && sz[j] > curr_sz / 2) {
            return get_centroid(j, node, curr_sz);
        }
    }
    return node;
}
int64_t ans = 0;
int cnt[N];

void add(int node, int p, int d) {
    cnt[d]++;
    for(auto j : adj[node]) {
        if(j != p && !mark[j]) {
            add(j, node, d + 1);
        }
    }
}
int MAXD = 0;
void get_ans(int node, int p, int d) {
    if(d > k) return;
    MAXD = max(MAXD, d);
    ans += cnt[k-d];
    for(auto j : adj[node]) {
        if(j != p && !mark[j]) {
            get_ans(j, node, d + 1);
        }
    }
}

void decompose(int node, int p) {
    int total = dfs_sz(node, p);
    int cen = get_centroid(node, p, total);
    mark[cen] = 1;

    MAXD = 0;
    cnt[0] = 1;
    for(auto j : adj[cen]) {
        if(j == p || mark[j]) continue;
        get_ans(j, cen, 1);
        add(j, cen, 1);
    }
    
    for(int i=0;i<=MAXD;i++) cnt[i] = 0;

    for(auto &j : adj[cen]) {
        if(j != p && !mark[j]) {
            decompose(j, cen);
        }
    }
}



int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decompose(1, -1);
    cout << ans << "\n";
    


    return 0;
}