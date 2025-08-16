#include <bits/stdc++.h>
using namespace std;
#define int long long

const int W = 1e5 + 5;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> val(n + 1), weight(n + 1);
    for(int i=1;i<=n;i++) {
        cin >> val[i] >> weight[i];
    }
    
    int sn = sqrt(n) + 1;
    vector<vector<int>> dp(sn + 1, vector<int>(W));

    for(int i=1;i<=sn;i++) {
        for(int j=1;j<W;j++) {
            int par = i / 2;
            dp[i][j] = dp[par][j];
            if(j - weight[i] >= 0) {
                dp[i][j] = max(dp[i][j], val[i] + dp[par][j - weight[i]]);
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int node, L;
        cin >> node >> L;
        if(node <= sn) {
            cout << dp[node][L] << "\n";
            continue;
        }

        vector<int> temp;
        int t = node;
        while(t > sn) {
            temp.push_back(t);
            t /= 2;
        }
        int ans = 0;
        int sz = temp.size();
        int MASK = (1 << sz);
        for(int m = 0; m < MASK; m++) {
            int profit = 0, wt = 0;
            for(int j=0;j<sz;j++) {
                if(m >> j & 1) {
                    profit += val[temp[j]];
                    wt += weight[temp[j]];
                }
            }
            if(wt <= L) {
                ans = max(ans, profit + dp[t][L - wt]);
            }
        }
        cout << ans << "\n";

    }


    return 0;
}