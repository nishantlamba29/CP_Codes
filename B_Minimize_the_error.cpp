#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> v(n);
    int k = k1 + k2;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[i] += x;
    }
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[i] -= x;
        v[i] = abs(v[i]);
    }

    sort(v.rbegin(), v.rend());

    for(int i=0;i<n;i++) {
        int next = (i + 1 < n) ? v[i + 1] : 0;  
        int diff = v[i] - next;  
        
        int cnt = i + 1;
        
        if(k >= cnt * diff) {
            for(int j=0;j<=i;j++) {
                k -= diff;
                v[j] = next;
            }
        }
        else {
            int q = k / cnt;
            for(int j=0;j<=i;j++) {
                v[j] -= q;
                k -= q;
            }
            for(int j=0;j<k;j++) {
                v[j]--;
            }
            k = 0;
            break;
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += (v[i] * v[i]);
    }

    cout << ans + k % 2 << "\n";

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