#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful
#define int long long
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 0x3f3f3f3f3f3f3f3fLL;;
const int mod = 998244353;

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<vector<int>> help(n + 1);
    for(int i=1;i<=n;i++) {
        int k;
        cin >> k;
        help[i].resize(k);
        for(int j=0;j<k;j++) {
            cin >> help[i][j];
        }
    }

    min_heap<pair<int, int>> pq;
    vector<int> dist(n + 1, inf);
    int to_add = 0;
    if(help[1].size() && help[1][0] == 0) {
        int j = 1;
        int prev = 0;
        to_add = 1;
        while(j < help[1].size()) {
            if(help[1][j] != prev + 1) break;
            to_add++;
            prev++;
            j++;
        }
    }
    pq.push({to_add, 1});
    dist[1] = to_add;

    while(pq.size()) {
        auto [d, node] = pq.top();
        pq.pop();
        if(dist[node] < d) continue;
        for(auto [j, c] : adj[node]) {
            int to_add = 0;
            int ind = lower_bound(help[j].begin(), help[j].end(), dist[node] + c) - help[j].begin();
            if(j != n && ind != help[j].size() && help[j][ind] == d + c) {
                to_add = 1;
                int prev = d + c;
                int lo = ind + 1, hi = help[j].size() - 1;
                int ans = ind;
                while(lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    if(help[j][mid] == help[j][ind] + mid - ind) {
                        lo = mid + 1;
                        ans = mid;
                    }
                    else {
                        hi = mid - 1;
                    }
                }
                to_add += (ans - ind);
            }
            if(dist[j] > dist[node] + c + to_add) {
                dist[j] = dist[node] + c + to_add;
                pq.push({dist[j], j});
            }
        }
    }

    int ans = dist[n];
    if(dist[n] == inf) ans = -1;
    cout << ans << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}