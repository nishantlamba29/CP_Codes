#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> f(k, vector<int>(26, 0));
    for(int i=0;i<n;i++) {
        f[i%k][s[i] - 'a']++;
    }
    int ans = 0;
    for(int i=0;i<k;i++) {
        int mx = 0, sum = 0;
        for(int j=0;j<26;j++) {
            sum += f[i][j] + f[k-i-1][j];
            mx = max(mx, f[i][j] + f[k-i-1][j]);
        }
        ans += (sum - mx);
    }
    cout << ans / 2 << "\n";
    
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