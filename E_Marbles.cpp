#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v[i]--;
    }

    vector<vector<int64_t>> cnt(20, vector<int64_t>(20));
    for(int i=0;i<20;i++) {
        for(int j=i+1;j<20;j++) {
            int64_t cnt1 = 0, cnt2 = 0;
            for(int k=0;k<n;k++) {
                if(v[k] == i) {
                    cnt[i][j] += cnt2;
                    cnt1++;
                }
                else if(v[k] == j) {
                    cnt[j][i] += cnt1;
                    cnt2++;
                }
            }
        }
    }

    vector<int64_t> dp(1 << 20, -1);
    function<int64_t(int)> rec = [&](int mask) {
        if(mask == (1 << 20) - 1) return 0LL;
        if(dp[mask] != -1) return dp[mask];

        int64_t ans = 1e18;
        for(int i=0;i<20;i++) {
            if(mask & (1 << i)) continue;
            int new_mask = mask | (1 << i);
            // i wale color ko j se phle place kr rha hu
            int64_t sum = 0;
            for(int j=0;j<20;j++) {
                if(mask & (1 << j))
                sum += cnt[j][i];
            }
            ans = min(ans, sum + rec(new_mask));
        }
        return dp[mask] = ans;
    };

    cout << rec(0) << "\n";

    return 0;
}