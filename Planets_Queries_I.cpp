#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    int LOG = 30;
    vector<vector<int>> dp(n + 1, vector<int>(LOG));
    vector<bool> vis(n + 1, 0);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        dp[i][0] = v[i];
    }

    for(int j=1;j<LOG;j++) {
        for(int i=1;i<=n;i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    while(q--) {
        int x, k;
        cin >> x >> k;
        int curr = x;
        for(int i=0;i<LOG;i++) {
            if(k >> i & 1) {
                curr = dp[curr][i];
            }
        }
        cout << curr << "\n";
    }

    

    return 0;
}