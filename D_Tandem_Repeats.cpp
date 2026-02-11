#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    
    int n = s.size();
    for(int len = 0; len * 2 <= n; len++) {
        int cnt = 0;
        for(int i=0;i+len < n; i++) {
            cnt += (s[i] == s[i+len] || s[i] == '?' || s[i+len] == '?');
            if(i-len >= 0) cnt -= (s[i] == s[i-len] || s[i] == '?' || s[i-len] == '?');
            if(cnt == len) ans = 2*len;
        }
    }

    cout << ans << "\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}