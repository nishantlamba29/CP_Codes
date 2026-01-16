#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void n_lamba_29() {

    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    set<char> st(a.begin(), a.end());
    vector<char> temp(st.begin(), st.end());

    int mn = min(k, (int)temp.size());
    int ans = 0;
    for(int mask = 0; mask < (1 << (int)temp.size()); mask++) {
        if(__builtin_popcount(mask) != mn) continue;
        vector<bool> mark(26, 0);
        for(int j=0;j<temp.size();j++) {
            if(mask >> j & 1) mark[temp[j] - 'a'] = 1;
        }
        int cnt = 0;
        int pairs = 0;
        for(int i=0;i<n;i++) {
            if(a[i] == b[i] || mark[a[i] - 'a']) cnt++;
            else {
                pairs += (cnt + 1) * cnt / 2;
                cnt = 0;
            }
        }
        pairs += cnt * (cnt + 1) / 2;
        ans = max(ans, pairs);
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