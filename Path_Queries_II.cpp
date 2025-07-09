#include <bits/stdc++.h>
using namespace std;

const int N = 2'000'05;
vector<int> adj[N+1];
int heavy[N+1], depth[N+1], value[N+1], pos[N+1];
int par[N+1], sz[N+1], top[N+1];
vector<int> order;

class SegTree {
public:
    int n;
    vector<int> t;
    SegTree(int size) {
        n = size;
        t.assign(2 * n, 0);
    }
    void build(const vector<int> &a) {
        for (int i = 0; i < n; ++i)
            t[i + n] = value[a[i]];
        for (int i = n - 1; i > 0; --i)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }
    void update(int pos, int val) {
        for (t[pos += n] = val; pos > 1; pos >>= 1)
            t[pos >> 1] = max(t[pos], t[pos ^ 1]);
    }
    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

SegTree *sg;

void dfs(int node, int p, int d) {
    sz[node] = 1;
    int maxi = 0;
    par[node] = p;
    depth[node] = d;
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node, d + 1);
        sz[node] += sz[j];
        if(sz[j] > maxi) {
            maxi = sz[j];
            heavy[node] = j;
        }
    }
}

void dfs2(int node, int t) { // t-> top
    top[node] = t;
    pos[node] = order.size();
    order.push_back(node);
    if(heavy[node]) {
        dfs2(heavy[node], t);
    }
    for(auto &j : adj[node]) {
        if(j == par[node] || j == heavy[node]) continue;
        dfs2(j, j);
    }
}

int query(int u, int v) {
    int res = 0;
    while (1) {
        int x = top[u];
        int y = top[v];
        if (x == y) {
            if (pos[u] > pos[v]) swap(u, v);
            res = max(res, sg->query(pos[u], pos[v]));
            break;
        }
        if (depth[x] > depth[y]) {
            res = max(res, sg->query(pos[x], pos[u]));
            u = par[x];
        } else {
            res = max(res, sg->query(pos[y], pos[v]));
            v = par[y];
        }
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> value[i];
    }
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    dfs2(1, 1);

    sg = new SegTree(n);
    sg->build(order);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int node, x;
            cin >> node >> x;
            value[node] = x;
            sg->update(pos[node], x);
        }
        else {
            int u, v;
            cin >> u >> v;
            cout << query(u, v) << " ";
        }
    }
    cout << "\n";

    return 0;
}