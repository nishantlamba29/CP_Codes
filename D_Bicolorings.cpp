#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

int dp[1001][2001][6];
int n, k;

// 0 -> dummy
// 1 -> WW
// 2 -> WB
// 3 -> BW
// 4 -> BB

vector<vector<int>> inc = {
    {1, 2, 2, 1},
    {0, 1, 1, 1},
    {0, 0, 2, 0},
    {0, 2, 0, 0},
    {1, 1, 1, 0}
};


int rec(int ind = 0, int curr = 0, int prev = 0) {
    if(curr > k) return 0;
    if(ind == n) {
        return curr == k;
    }
    int &ans = dp[ind][curr][prev];
    if(ans != -1) return ans;
    ans = 0;
    for(int i=0;i<4;i++) {
        ans = (ans + rec(ind + 1, curr + inc[prev][i], i + 1)) % mod;
    }
    return ans;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            for(int l=0;l<5;l++) dp[i][j][l] = -1;
        }
    }
    cout << rec();

    return 0;
}