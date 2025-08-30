#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '1') {
            cnt++;
            if(cnt >= k) {
                cout << "NO\n";
                return;
            }
        }
        else cnt = 0;
    }

    vector<int> ans(n);
    int k2 = 1;
    for(int i=0;i<n;i++) {
        if(s[i] == '1') {
            ans[i] = k2++;
        }
    }
    for(int i=0;i<n;i++) {
        if(ans[i] == 0) {
            ans[i] = k2++;
        }
    }
    cout << "YES\n";
    for(int i : ans) cout << i << " ";
    cout << "\n";

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