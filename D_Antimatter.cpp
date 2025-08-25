#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int dp[1005][10005];
int dp2[1005][10005];
int mp[40005];
int n;
int v[1005];

void reset(int dp[][10005], int l, int r, int MAX) {
    for(int i=l;i<=r;i++) {
        for(int j=0;j<=MAX;j++) dp[i][j] = 0;
    }
}

int func(int l, int r) {
    if(l >= r) return 0;
    int mid = (l + r) >> 1;

    int ans = 0;
    ans = (ans + func(l, mid)) % mod;
    ans = (ans + func(mid + 1, r)) % mod;

    // dp[i][j] = dp[i+1][j] + dp[i+1][j-v[i]]
    int MAX = 0;
    for(int i=l;i<=r;i++) MAX += v[i];

    int offset = 2*MAX;
    for(int i=0;i<=MAX + offset ;i++) mp[i] = 0;

    reset(dp, l, mid + 1, MAX);
    dp[mid + 1][0] = 1;

    int s1 = 0;
    for(int i=mid;i>=l;i--) {
        s1 += v[i];
        for(int j=0; j <= MAX; j++) {
            dp[i][j] = dp[i + 1][j];
            if(j - v[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j - v[i]]) % mod;
            }
            int val = s1 - 2 * j + offset;
            mp[val] = (mp[val] + dp[i][j]) % mod;
        }
    }

    // dp2[i][j] = dp2[i-1][j] + dp2[i-1][j-v[i]]
    reset(dp2, mid, r, MAX);
    dp2[mid][0] = 1;

    int s2 = 0;
    for(int i=mid+1;i<=r;i++) {
        s2 += v[i];
        for(int j=0; j <= MAX; j++) {
            dp2[i][j] = dp2[i - 1][j];
            if(j - v[i] >= 0) {
                dp2[i][j] = (dp2[i][j] + dp2[i - 1][j - v[i]]) % mod;
            }
            int val = 2 * j - s2 + offset;
            ans = (ans + mp[val] * dp2[i][j]) % mod;
        }
    }

    return ans;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = func(0, n - 1);
    cout << ans << "\n";


    return 0;
}