#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = (int)1e9 + 7;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    
    int n;
    cin >> n;
    vector<int> v(n+1);
    int N = 0;
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        N = max(N, v[i]);
    }

    vector<vector<int>> divisors(N+1);

    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j+=i) {
            divisors[j].push_back(i);
        }
    }


    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++) {
        sort(divisors[v[i]].rbegin(), divisors[v[i]].rend());
        for(auto &j : divisors[v[i]]) {
            if(j <= i) {
                dp[j] = (dp[j] + dp[j-1]) % mod;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = (ans + dp[i]) % mod;
    }

    cout << ans << "\n";

    return 0;
}