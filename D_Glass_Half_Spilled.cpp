#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

const int inf = 0x3f3f3f3f3f3f3f3fLL;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pair<int,int>> v(n+1);

    ld sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>v[i].first>>v[i].second;
        sum += v[i].second;
    }

    int m = 101*n;
    // dp[i][j][k]
    // means out of i glasses we chose j glasses having sum of their capacity k
    // dp = sum of v[i].second of those j glasses
    vector<vector<int>> prev(n+1, vector<int>(m+1, -inf)), curr(n+1, vector<int>(m+1, -inf));
    
    prev[0][0] = 0;
    curr[0][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                // not take
                curr[j][k] = prev[j][k];
                if(k >= v[i].first) // take
                    curr[j][k] = max(curr[j][k], prev[j-1][k-v[i].first] + v[i].second);
            }
        }
        prev = curr;
    }

    // total water = sum
    // selected glasses ka contribution i.e. unke v[i].second ka sum = prev[j][k]
    // aur remainng glass m water = sum - prev[j][k]
    // remainng m se adha spill and adha transfer so
    // ans = prev[j][k] + (sum - prev[j][k]) / 2;
    vector<ld> ans(n+1, 0);

    for(int j=1;j<=n;j++){
        for(int k=1;k<=m;k++){
            // prev[j][k] is present if we selected j glass having total water in them = prev[j][k]
            // (sum - prev[j][k]) / 2   is spilled 
            // total = prev[j][k] + (sum - prev[j][k]) / 2
            // = (prev[j][k] + sum) / 2
            // k is sum of all v[i].first of j chosen glasses
            // so ans = min(k, (prev[j][k] + sum) / 2)
            // taking maximum over all k
            ans[j] = max(ans[j], min((ld)k, (ld)(prev[j][k] + sum)/2));
        }
    }

    for(int i=1;i<=n;i++) cout<<fixed<<setprecision(10)<<ans[i]<<" ";

}