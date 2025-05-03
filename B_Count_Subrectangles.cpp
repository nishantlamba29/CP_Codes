#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    vector<int> t1(n+1, 0), t2(m+1, 0);

    int lo = 0;
    while (lo < n) {
        int cnt = 0;
        while (lo < n && a[lo] == 1) {
            lo++;
            cnt++;
        }
        lo++;
        int val = 1;
        for (int j = cnt; j >= 1; j--) {
            t1[j] += val;
            val++;
        }
    }
    lo = 0;
    while (lo < m) {
        int cnt = 0;
        while (lo < m && b[lo] == 1) {
            lo++;
            cnt++;
        }
        lo++;
        int val = 1;
        for (int j = cnt; j >= 1; j--) {
            t2[j] += val;
            val++;
        }
    }

    vector<int> divisors;
    for(int i=1;i*i<=k;i++) {
        if(k % i == 0) {
            divisors.push_back(i);
            if(i*i != k) divisors.push_back(k / i);
        }
    }

    sort(divisors.begin(), divisors.end());
    
    int ans = 0;
    for(auto p : divisors) {
        int q = k / p;
        if(p <=n && q <= m)
        ans += (t1[p] *  t2[q]);
    }

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _ = 1;
    // cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}