#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int dp[N];

void dfs(int node, int p, int mid, int &cnt) {
    for(auto j : adj[node]) {
        if(j != p) {
            dfs(j, node, mid, cnt);
            dp[node] = max(dp[node], dp[j] + 1);
        }
    }
    if(dp[node] + 1 == mid && node != 1 && p != 1) {
        dp[node] = -1;
        cnt++;
    }
}

bool check(int n, int mid, int k) {
    int cnt = 0;
    for(int i=0;i<=n;i++) dp[i] = 0;
    dfs(1, -1, mid, cnt);
    if(dp[1] > mid) return 0;
    return cnt <= k;
}

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
    }

    for(int i=2;i<=n;i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    int lo = 0, hi = n, ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(check(n, mid, k)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
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