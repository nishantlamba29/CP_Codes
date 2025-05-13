#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<pair<int,int>> dp(1<<n, {n+1, 0});
    dp[0] = {1, 0};
    for(int mask=0;mask<(1<<n);mask++) {
        for(int i=0;i<n;i++) {
            if(!(mask & (1<<i))) {
                int new_mask = mask | (1<<i);
                auto [ride, last] = dp[mask];
                if(last + v[i] <=  x) {
                    dp[new_mask] = min(dp[new_mask], {ride, last + v[i]});
                }
                else {
                    dp[new_mask] = min(dp[new_mask], {ride + 1, v[i]});
                }
            }
        }
    }

    cout << dp[(1<<n) - 1].first << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}