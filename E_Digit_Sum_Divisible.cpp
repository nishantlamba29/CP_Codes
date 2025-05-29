#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int dp[15][2][130][130];

int solve(int ind, int tight, int sum, int rem, int target) {
    if(sum > target) return 0;
    if(ind == s.size()) {
        if(sum == target && rem == 0) return 1;
        return 0;
    }
    if(dp[ind][tight][sum][rem] != -1) return dp[ind][tight][sum][rem];

    int limit = tight ? s[ind] - '0' : 9;
    int ans = 0;
    for(int i=0;i<=limit;i++) {

        int new_rem = (rem * 10 + i) % target;
        ans += solve(ind + 1, tight & (i == limit), sum + i, new_rem, target);

    }

    return dp[ind][tight][sum][rem] = ans;

}

void solve() {
    
    cin >> s;
    int ans = 0;
    for(int i=1;i<=130;i++) {
        memset(dp, -1, sizeof(dp));
        ans += solve(0, 1, 0, 0, i);
    }

    cout << ans << "\n";

}

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}