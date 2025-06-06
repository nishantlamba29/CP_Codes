#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = (int)1e17;

inline void n_lamba_29() {
    int n, w, b, x;
    cin >> n >> w >> b >> x;

    vector<int> c(n), cost(n);
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin >> c[i];
        sum += c[i];
    }
    for(int i=0;i<n;i++) cin >> cost[i];

    vector<vector<int>> dp(n+2, vector<int>(sum + 3, -inf));
    dp[0][0] = w;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=sum;j++) {
            // curr index j birds -> max mana points left
            if(dp[i][j] == -inf) break;
            int cap = b * j + w;
            int restored = dp[i][j] + x;
            restored = min(restored, cap);

            dp[i+1][j] = max(dp[i+1][j], restored);
            

            for(int k=0;k<=c[i];k++) {
                if(dp[i][j] >= k * cost[i]) { // mana points left > 
                    int val = dp[i][j] - k * cost[i] + x; // points minus and restore
                    val = min(val, cap + k * b);
                    dp[i+1][j+k] = max(dp[i+1][j+k], val);
                }
            }
        }
    }

    int ans = -1;
    for(int i = sum; i >= 0; i--) {
        if(dp[n][i] >= 0) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}