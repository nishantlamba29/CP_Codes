#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int> pre = v;
    for(int i=1;i<n;i++) pre[i] += pre[i-1];

    auto fun = [&](int l, int r){
        return pre[r] - (l > 0 ? pre[l-1] : 0);
    };

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j = i + len - 1;
            if(i == j){
                dp[i][j] = v[i];
                continue;
            }
            int left = v[i] + fun(i+1, j) - dp[i+1][j];
            int right = v[j] + fun(i,j-1) - dp[i][j-1];
            dp[i][j] = max(left, right);
        }
    }
    cout<<dp[0][n-1];

}