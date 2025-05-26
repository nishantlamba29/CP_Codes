#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    string s = "";
    while(n > 0) {
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());

    vector<vector<vector<int>>> dp(63, vector<vector<int>>(63, vector<int>(3, -1)));
    vector<vector<vector<int>>> dp2(63, vector<vector<int>>(63, vector<int>(3, -1)));

    function<pair<int,int>(int, int, int)> solve = [&](int ind, int cnt, int tight) {
        if(cnt > k) return make_pair(0LL, 0LL);
        if(ind == s.size()) {
            return make_pair((cnt == k ? 1LL : 0LL), 0LL);
        }

        if(dp[ind][cnt][tight] != -1) return make_pair(dp[ind][cnt][tight], dp2[ind][cnt][tight]);

        int limit = tight ? (s[ind] - '0') : 1;
        int ans = 0, sum = 0; // count ans sum

        for(int i=0;i<=limit;i++) {
            auto [cnt2, sum2] = solve(ind + 1, cnt + i, tight && (i == limit));

            int wt = 1LL << (s.size() - 1 - ind);
            ans = (ans + cnt2) % mod; // count 
            sum = (sum + (sum2 + (i * ((wt % mod) * (cnt2 % mod)) % mod) % mod) % mod) % mod; // sum
        }
        return make_pair(dp[ind][cnt][tight] = ans, dp2[ind][cnt][tight] = sum);
    };
    
    int ans = solve(0, 0, 1).second;

    cout << ans << "\n";

}

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}