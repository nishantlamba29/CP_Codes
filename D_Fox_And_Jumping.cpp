#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e17;

vector<int> get_prime(int num) {
    vector<int> temp;
    for(int i=2;i*i<=num;i++) {
        if(num % i == 0) {
            while(num % i == 0) {
                num /= i;
            }
            temp.push_back(i);
        }
    }
    if(num > 1) temp.push_back(num);
    return temp;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> l(n), c(n);
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) cin >> c[i];

    int ans = inf;

    function<int(int, int, int, vector<int>&, vector<vector<int>>&)> rec = [&](int mask, int ind, int sz, vector<int> &v, vector<vector<int>> &dp) {
        if(mask == (1 << sz) - 1) {
            return 0LL;
        }
        if(ind == v.size()) return inf;
        auto &res = dp[ind][mask];
        if(res != -1) return res;

        int take = rec(mask | v[ind], ind + 1, sz, v, dp) + c[ind];
        int notake = rec(mask, ind + 1, sz, v, dp);
        return res = min(take, notake);
    };

    for(int i=0;i<n;i++) {
        if(l[i] == 1) {
            ans = min(ans, c[i]);
            continue;
        }
        auto prime = get_prime(l[i]);
        int sz = prime.size();

        vector<int> mask(n);
        for(int j=0;j<n;j++) {
            if(j == i) continue;
            int m = 0;
            for(int k=0;k<sz;k++) {
                if(l[j] % prime[k] != 0) {
                    m |= (1 << k);
                }
            }
            mask[j] = m;
        }
        vector<vector<int>> dp(n, vector<int>(1 << sz, -1));
        int res = rec(0, 0, sz, mask, dp);

        ans = min(ans, res + c[i]);

    }

    if(ans == inf) ans = -1;
    cout << ans << "\n";

    return 0;
}