#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2'000'05;
vector<int> adj[N+1];
int heavy[N+1], depth[N+1], value[N+1], pos[N+1];
int par[N+1], sz[N+1], top[N+1];
vector<int> order;

class SegTree {
private:
    int len;
    vector<int> t;
    void build(int v, vector<int> &a, int tl, int tr) {
        if(tl == tr) {
            t[v] = value[a[tl]];
            return; 
        }
        int tm = (tl + tr) >> 1;
        build(v << 1, a, tl, tm);
        build(v << 1 | 1, a, tm + 1, tr);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
    void update(int v, int tl, int tr, int id, int val) {
        if(tl == id && tr == id) {
            t[v] = val;
            return;
        }
        if(id > tr || id < tl) return;
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, id, val);
        update(v << 1 | 1, tm + 1, tr, id, val);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(tl > r || tr < l) return 0;
        if(l <= tl && r >= tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return left + right;
    }
public:
    SegTree(int _n) {
        len = _n;
        t.resize(4 * len);
    }    
    void build(vector<int> &a) {
        build(1, a, 0, len - 1);
    }
    void update(int ind, int val) {
        update(1, 0, len - 1, ind, val);
    }
    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
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

int64_t query(int u, int v) {
    int64_t res = 0;
    while (1) {
        int x = top[u];
        int y = top[v];
        if (x == y) {
            if (pos[u] > pos[v]) swap(u, v);
            res += sg->query(pos[u], pos[v]);
            break;
        }
        if (depth[x] > depth[y]) {
            res += sg->query(pos[x], pos[u]);
            u = par[x];
        } else {
            res += sg->query(pos[y], pos[v]);
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
            int u;
            cin >> u;
            cout << query(1, u) << "\n";
        }
    }

    return 0;
}