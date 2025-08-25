#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;
const int inf = 1e18;
int n, a, b, v[N];
int dp[N][3];

vector<int> calculate_prime(int n) {
    vector<int> res;
    for(int i=2;i*i<=n;i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            res.push_back(i);
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}

int get_ans(int p) {
    for(int i=0;i<=n;i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = inf;
    }
    dp[0][1] = a;
    if(v[0] % p == 0) {
        dp[0][0] = 0;
    }
    else if((v[0] + 1) % p == 0 || (v[0] - 1) % p == 0) {
        dp[0][0] = b;
    }
    for(int i=1;i<n;i++) {
        if(v[i] % p == 0) {
            dp[i][0] = dp[i-1][0];
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
        }
        else if(((v[i] + 1) % p == 0) || ((v[i] - 1) % p == 0)) {
            dp[i][0] = b + dp[i-1][0];
            dp[i][2] = b + min(dp[i-1][1], dp[i-1][2]);
        }
        dp[i][1] = a + min(dp[i-1][0], dp[i-1][1]);
    }

    return min({dp[n-1][1], dp[n-1][2], dp[n-1][0]});
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;
    
    for(int i=0;i<n;i++) cin >> v[i];

    set<int> st = {v[0], v[0] - 1, v[0] + 1, v[n-1], v[n-1] + 1, v[n-1] - 1};

    int ans = inf;
    for(auto p : st) {
        vector<int> primes = calculate_prime(p);
        for(int pr : primes) {
            ans = min(ans, get_ans(pr));
        }
    }

    cout << ans << "\n";

    return 0;
}