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
    vector<vector<int>> v(n, vector<int>(3));
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1]>>v[i][2];

    sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    });
    vector<int> end(n);
    for(int i=0;i<n;i++) end[i] = v[i][1];
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int j = lower_bound(end.begin(), end.end(), v[i-1][0]) - end.begin();
        dp[i] = max(dp[i-1], v[i-1][2] + dp[j]);
    }
    cout<<dp[n];
}