#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> f(n + 1);
    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        f[l]++;
        f[r+1]--;
    }
    for(int i=1;i<n;i++) f[i] += f[i-1];

    int64_t ans = 0;
    sort(v.rbegin(), v.rend());
    sort(f.rbegin(), f.rend());

    for(int i=0;i<n;i++) {
        ans += 1LL * f[i] * v[i];
    }
    cout << ans << "\n";

    return 0;
}