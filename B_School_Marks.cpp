#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    
    vector<int> v(k);
    for(int i=0;i<k;i++) {
        cin >> v[i];
    }
    if(y > x) {
        cout << -1;
        return 0;
    }
    
    int cnt = count_if(v.begin(), v.end(), [&](int x) {
        return x < y;
    });

    if(cnt > n / 2) {
        cout << -1;
        return 0;
    }

    int need = (n + 1) / 2;    // y needed
    int curr = k - cnt; // x >= y in v
    int m = max(0LL, need - curr); // y to be added

    for(int i=0;i<m;i++) v.push_back(y);
    for(int i=0;i<n-k-m;i++) v.push_back(1);

    int sum = accumulate(v.begin(), v.end(), 0LL);

    if(sum > x) cout << -1;
    else for(int i=k;i<n;i++) cout << v[i] << " ";

    return 0;
}