#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int f;
    cin >> f;
    vector<int> h(f + 1);
    for(int i=1;i<=f;i++) cin >> h[i];
    int k;
    cin >> k;
    vector<int> p(k);
    vector<int> without_car(f + 1, 0);

    vector<int> vmask(n + 1, 0); // denotes a mask whose setbits tell without car friend

    for(int i=0;i<k;i++) {
        cin >> p[i];
        without_car[p[i]] = 1;
        vmask[h[p[i]]] |= (1 << i);
    }
    int mask = (1 << k);
    vector<int> dist(n + 1, -1);

    vector<vector<bool>> vis(n + 1, vector<bool>(mask, 0)); // tell that shostest path from 0 to v visits exactly mask friends without car

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1][vmask[1]] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto &j : adj[node]) {
            if(dist[j] == -1) {
                dist[j] = dist[node] + 1;
                q.push(j);
            }
            if(dist[j] == dist[node] + 1) {
                for(int m=0;m<mask;m++) {
                    if(vis[node][m]) {
                        vis[j][m | vmask[j]] = 1;
                    }
                }
            }
        }
    }

    vector<int> dp(mask, 0);

    dp[0] = 1;

    for(int i=1;i<=f;i++) {
        int driver = h[i];
        if(without_car[i]) continue;
        // marking all submasks
        for(int m = 0; m < mask; m++) {
            if(vis[driver][m]) {
                int sub = m;
                while(1) {
                    vis[driver][sub] = 1;
                    if(sub == 0) break;
                    sub = (sub - 1) & m;
                }
            }
        }

        vector<int> dp2 = dp;
        for(int m = 0; m < mask; m++) {
            if(vis[driver][m]) {
                for(int m2 = 0; m2 < mask; m2++) {
                    if(dp[m2]) {
                        dp2[m2 | m] = 1;
                    }
                }
            }
        }

        dp = dp2;


    }

    int mx = 0;
    for(int m=0;m<mask;m++) {
        if(dp[m]) {
            mx = max(mx, __builtin_popcount(m));
        }
    }

    int ans = k - mx;

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}