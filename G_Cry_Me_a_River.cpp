#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> radj[N];
int dp1[N], dp2[N], cnt[N];
// dp1 Cry turn Cry win
// dp2 River turn Cry win

// turning red
void update(int node) {
    queue<pair<int, int>> q;
    if(dp1[node]) {
        dp1[node] = 0;
        q.push({node, 1});
    }
    if(dp2[node]) {
        dp2[node] = 0;
        q.push({node, 2});
    }

    while(q.size()) {
        auto &[node, type] = q.front();
        q.pop();

        for(auto &j : radj[node]) {
            if(type == 1) { // River turn at j
                if(dp2[j]) {
                    dp2[j] = 0;
                    q.push({j, 2});
                }
            }
            else { // Cry turn at j
                cnt[j]--;
                if(cnt[j] == 0) {
                    dp1[j] = 0;
                    q.push({j, 1});
                }
            }
        }
    }
}

inline void n_lamba_29() {
    
    int n, m, qry;
    cin >> n >> m >> qry;
    for(int i=0;i<=n;i++) {
        radj[i].clear();
        dp1[i] = dp2[i] = 1;
        cnt[i] = 0;
    }

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        radj[v].push_back(u);
        cnt[u]++;
    }

    while(qry--) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            update(b);
        }
        else {
            cout << (dp1[b] ? "YES\n" : "NO\n");
        }
    }

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