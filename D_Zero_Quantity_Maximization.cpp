#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int zr = 0;
    for(int i=0;i<n;i++) {
        cin >> b[i];
        if(b[i] == 0) zr++;
    }

    map<pair<int,int>, int> mp;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == 0 && b[i] == 0) {
            cnt++;
            continue;
        }
        if(a[i] == 0 || b[i] == 0) continue;
        int g = gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;
        int sign = -1;
        if(b[i] < 0) sign *= -1;
        if(a[i] < 0) sign *= -1;
        mp[{sign * abs(b[i]), abs(a[i])}]++;
    }

    int ans = 0;
    for(auto [it, f] : mp) {
        ans = max(ans, f);
    }

    cout << max(zr, ans + cnt) << "\n";


    return 0;
}