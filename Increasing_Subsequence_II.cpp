#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
 
struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int _n) {
        n = _n;
        bit.resize(n + 1);
    }
    void update(int ind, int val) {
        while(ind <= n) {
            (bit[ind] += val) %= mod;
            ind += ind & -ind;
        }
    }
    int query(int id) {
        int res = 0;
        while(id > 0) {
            (res += bit[id]) %= mod;
            id -= id & -id;
        }
        return res;
    }
};
 
int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> temp;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        temp.push_back(v[i]);
    }
 
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
 
    for(int i=0;i<n;i++) {
        v[i] = upper_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
    }
 
    vector<int> dp(n + 1);
    Fenwick f(n + 1);
    int ans = 0;
    for(int i=0;i<n;i++) {
        int sum = f.query(v[i] - 1);
        dp[v[i]] = (1 + sum) % mod;
        f.update(v[i], dp[v[i]]);
        ans = (ans + dp[v[i]]) % mod;
    }
 
    cout << ans << "\n";
 
    return 0;
}