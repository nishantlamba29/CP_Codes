#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n, m;
int dp[1001][11][1025];

int rec(int i = 0, int j = 0, int mask = 0) {
    if(i == n) {
        return (__builtin_popcount(mask) == m);
    }
    int &res = dp[i][j][mask];
    if(res != -1) return res;
    if(j == m) {
        return res = rec(i + 1, 0, mask);
    }

    int horizontal = 0, leave = 0;
    if(i > 0 && !(1 & mask)) {
        int new_mask = mask >> 1;
        new_mask |= (1 << (m-1));
        return res = rec(i, j + 1, new_mask);
    }
    if(j > 0 && !((1 << (m-1)) & mask)) {
        int new_mask = mask >> 1;
        new_mask |= (1 << (m-1));
        if(m - 2 >= 0) new_mask |= (1 << (m-2));
        horizontal = (horizontal + rec(i, j + 1, new_mask)) % mod;
    }
    int new_mask = mask >> 1;
    leave = rec(i, j + 1, new_mask);
    return res = (leave + horizontal) % mod;

}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    memset(dp, -1, sizeof(dp));

    cout << rec() << "\n";

    return 0;
}