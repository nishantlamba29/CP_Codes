#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> u(n), s(n);
    for(int i=0;i<n;i++) cin >> u[i];
    for(int i=0;i<n;i++) cin >> s[i];

    vector<vector<int>> b(n+1);
    for(int i=0;i<n;i++) {
        b[u[i]].push_back(s[i]);
    }
    for(int i=1;i<=n;i++) {
        sort(b[i].rbegin(), b[i].rend());
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<b[i].size();j++) {
            b[i][j] += b[i][j-1];
        }
    }

    vector<int> ans(n+1);

    for(int i=1;i<=n;i++) {
        for(int j=0;j<b[i].size();j++) {
            int val = b[i].size();
            if(val % (j+1) != 0) {
                val -= val % (j+1);
            }
            ans[j+1] += b[i][val - 1];
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
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