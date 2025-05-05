#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int ans = v[n/2].first - v[(n-1)/2].first + 1;
    sort(v.begin(), v.end(), [&](const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    });
    ans *= (v[n/2].second - v[(n-1)/2].second + 1);
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