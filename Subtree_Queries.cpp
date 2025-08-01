#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
vector<int> adj[N];
int val[N], inTime[N], sz[N], arr[N];

int timer = 1;
void dfs(int node = 1, int p = -1) {
    arr[timer] = val[node];
    inTime[node] = timer++;
    sz[node] = 1;
    for(auto &j : adj[node]) {
        if(j != p) {
            dfs(j, node);
            sz[node] += sz[j];
        }
    }
}

class Fenwick {
    int n;
    vector<int> bit;
public:
    Fenwick(int n) {
        this->n = n;
        bit = vector<int>(n+1, 0);
    }

    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }

    int query(int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= id & -id;
        }
        return ans;
    }
};

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> val[i+1];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    Fenwick f(n+1);
    for(int i=1;i<=n;i++) {
        f.update(i, arr[i]);
    }

    for(int i=0;i<q;i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int s, x;
            cin >> s >> x;
            int ind = inTime[s];
            f.update(ind, -arr[ind]);
            f.update(ind, x);
            arr[ind] = x;
        }
        else {
            int node;
            cin >> node;
            int l = inTime[node];
            int r = l + sz[node] - 1;
            cout << f.query(r) - f.query(l - 1) << "\n";
        }
    }


    return 0;
}