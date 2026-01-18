#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    if(s[0] == s.back() || t[0] == t.back()) {
        cout << "NO\n";
        return;
    }
    if((s[0] == '<' && t[0] == '^') || (s[0] == '>' && t[0] == 'v')) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int _;
    // cin >> _;
    // while (_-->0) {
        solve();
    // }

    return 0;
}