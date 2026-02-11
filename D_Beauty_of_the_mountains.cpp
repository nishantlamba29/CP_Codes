#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> mat[i][j];
    }
    vector<string> typ(n);
    for(int i=0;i<n;i++) cin >> typ[i];

    vector<vector<int64_t>> pre(n + 1, vector<int64_t>(m + 1));

    int64_t curr = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            curr += (typ[i][j] == '0' ? mat[i][j] : -mat[i][j]);
        }
    }

    if(curr == 0) {
        cout << "YES\n";
        return;
    }

    for(int i=1;i<=n;i++) pre[i][1] = pre[i-1][1] + (typ[i-1][0] == '0' ? 1 : -1);
    for(int j=1;j<=m;j++) pre[1][j] = pre[1][j-1] + (typ[0][j-1] == '0' ? 1 : -1);

    for(int i=2;i<=n;i++) {
        for(int j=2;j<=m;j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (typ[i-1][j-1] == '0' ? 1 : -1);
        }
    }

    int64_t g = 0;
    for(int i=k;i<=n;i++) {
        for(int j=k;j<=m;j++) {
            int64_t diff = pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k];
            g = gcd(g, diff);
        }
    }

    if(g == 0) {
        cout << "NO\n";
        return;
    }
    if(curr % g == 0) cout << "YES\n";
    else cout << "NO\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}