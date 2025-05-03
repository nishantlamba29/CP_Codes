#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        v[i].first = a[i];
        v[i].second = i + 1;
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    vector<int> vis(n+2, 0);
    for(int i=0;i<n;i++) {
        int ind = v[i].second;
        if(vis[ind - 1] || vis[ind + 1]) {
            vis[ind] = 1;
        }
        else {
            ans++;
            vis[ind] = 1;
        }
    }
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