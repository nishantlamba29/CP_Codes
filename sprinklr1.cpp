// #include "bits/stdc++.h"
// using namespace std;

// int dp[60][60][61];

// int fun(int l, int r, int k, vector<char>&a){
//     if(l>r) return 0;
//     if(dp[l][r][k]!=-1) return dp[l][r][k];
//     int mx=(k+1)*(k+1)+fun(l+1,r,0,a);
//     for(int i=l+1; i<=r; i++){
//         if(a[i]==a[l]){
//             mx=max(mx,fun(l+1,i-1,0,a)+fun(i,r,k+1,a));
//         }
//     }
//     return dp[l][r][k]=mx;
// }

// void solve(){
//     int n; cin>>n;
//     vector<char>a(n);
//     for(auto &x:a) cin>>x;
//     fill_n(&dp[0][0][0],60*60*61,-1);
//     cout<<fun(0,n-1,0,a);
// }

// int main(){
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
int rec(int l, int r, int k, vector<char> &v, vector<vector<vector<int>>> &dp)
{
    if (l > r)
        return 0;
    if (dp[l][r][k] != -1)
        return dp[l][r][k];
    int op1 = (k + 1) * (k + 1) + rec(l + 1, r, 0, v, dp);
    for (int i = l + 1; i <= r; i++)
    {
        if (v[i] == v[l])
            op1 = max(op1, rec(l + 1, i - 1, 0, v, dp) + rec(i, r, k + 1, v, dp));
    }
    return dp[l][r][k] = op1;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
    int ans = rec(0, n - 1, 0, v, dp);
    cout << ans << "\n";
    return 0;
}

/*

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPoints(vector<char>& colors) {
    int N = colors.size();
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));

    for (int len = 1; len <= N; ++len) {
        for (int l = 0; l + len - 1 < N; ++l) {
            int r = l + len - 1;
            for (int k = 0; k <= l; ++k) {
                int points = (k + 1) * (k + 1) + (l + 1 <= r ? dp[l + 1][r][0] : 0);
                dp[l][r][k] = max(dp[l][r][k], points);
                for (int m = l + 1; m <= r; ++m) {
                    if (colors[m] == colors[l]) {
                        dp[l][r][k] = max(dp[l][r][k], dp[l + 1][m - 1][0] + dp[m][r][k + 1]);
                    }
                }
            }
        }
    }

    return dp[0][N-1][0];
}

int main() {
    int N;
    cin >> N;
    vector<char> colors(N);
    for (int i = 0; i < N; ++i) {
        cin >> colors[i];
    }

    cout << maxPoints(colors) << endl;
    return 0;
}

*/