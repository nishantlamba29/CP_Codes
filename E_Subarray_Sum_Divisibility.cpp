#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e17;

int n, m, l;
vector<int> v;
vector<vector<int>> cnt;


inline void n_lamba_29() {

    cin >> n >> m >> l;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> g(l);
    for(int i=0;i<n;i++) {
        g[i % l].push_back(v[i]);
    }

    cnt.resize(l, vector<int>(m));
    for(int i = 0; i < l; i++) {
        for(int j=0;j<m;j++) {
            for(int ele : g[i]) {
                cnt[i][j] += (j - ele + m) % m; 
            }
        }
    }

    vector<vector<int>> dp(l + 1, vector<int>(m + 1, inf));

    for(int i=0;i < m;i++){
        dp[0][i] = cnt[0][i];
    }

    for(int i=1;i<l;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<m;k++) {
                int op = cnt[i][k];
                int x = (j - k + m) % m;
                dp[i][j] = min(dp[i][j], op + dp[i-1][x]);
            }
        }
    }

    cout << dp[l-1][0] << '\n';

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}