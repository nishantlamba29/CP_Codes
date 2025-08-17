#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int m1 = -1e17, m2 = 1e17;
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        if(v[i].second > 0) {
            m2 = min(m2, v[i].first);
        }
        else m1 = max(m1, v[i].first);
    }

    if(m1 < m2) {
        cout << "-1\n";
        return 0;
    }

    auto check = [&](double mid) {
        double m2 = 1e30;
        for(int i=n-1;i>=0;i--) {
            double np = (double)v[i].first + (double)mid * v[i].second;
            if(v[i].second > 0 && np >= m2) {
                return 1;
            }
            if(v[i].second < 0) m2 = min(m2, np);
        }
        return 0;
    };

    double lo = 0, hi = 1e9, ans = -1;
    for(int itr = 0; itr < 100 ;itr++) {
        double mid = (lo + hi) / 2.0;
        if(check(mid)) {
            hi = mid;
            ans = mid;
        }
        else lo = mid;
    }

    cout << fixed << setprecision(20) << ans << "\n";


    return 0;
}