#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;
int par[N], sz[N], version[N];

int find(int x, int t) {
    if(par[x] == x || version[x] > t) return x;
    return find(par[x], t);
}

bool merge(int u, int v, int t) {
    int p1 = find(u, t), p2 = find(v, t);
    if(p1 == p2) return 0;
    if(sz[p1] > sz[p2]) swap(p1, p2);
    par[p1] = p2;
    sz[p2] += sz[p1];
    version[p1] = t;
    return 1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<=n;i++) {
        par[i] = i;
        sz[i] = 1;
        version[i] = inf;
    }
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v, i + 1);
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(u == v) {
            cout << 0 << "\n";
            continue;
        }
        int lo = 1, hi = m + 1, ans = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(find(u, mid) == find(v, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}