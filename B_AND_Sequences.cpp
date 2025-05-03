#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = (int)1e9 + 7;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    int mini = (int)1e9;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        mini = min(mini, v[i]);
    }
    int cnt = count(v.begin(), v.end(), mini);
    if(cnt < 2) {
        cout << "0\n";
        return;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<30;j++) {
            if(mini >> j & 1LL) {
                if(v[i] >> j & 1LL){}
                else {
                    cout << "0\n";
                    return;
                }
            }
        }
    }

    int ans = 1;
    for(int i=2;i<=n-2;i++) {
        ans = (ans * i) % mod;
    }
    ans = (ans * cnt) % mod;
    ans = (ans * (cnt - 1)) % mod;

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}