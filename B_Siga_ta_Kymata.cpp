#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> pos(n + 1);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        pos[v[i]] = i + 1;
    }
    string s;
    cin >> s;

    if(s[0] == '1' || s[n-1] == '1' || s[pos[1]-1] == '1' || s[pos[n]-1] == '1') {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> ans;
    vector<int> vis(n + 1, 0);

    auto chk = [&](int l, int r) {
        l--, r--;
        if(l == r) return;
        if(l > r) swap(l, r);
        for(int i=0;i<n;i++) {
            if(s[i] == '1' && !vis[i] && v[i] > min(v[l], v[r]) && v[i] < max(v[l], v[r])) {
                vis[i] = 1;
            }
        }
        l++, r++;
        ans.push_back({l, r});    
    };

    chk(1, pos[1]);
    chk(1, pos[n]);
    chk(n, pos[1]);
    chk(n, pos[n]);
    chk(pos[1], pos[n]);

    for(int i=0;i<n;i++) {
        if(s[i] == '1' && !vis[i]) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << "\n";
    for(auto [l, r] : ans) cout << l << " " << r << "\n";


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