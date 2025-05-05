#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = (int)1e9;

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        pos[v[i]].push_back(i+1);
    }

    vector<int> ans(n+1, inf);
    for(int i=1;i<=n;i++) {
        if(pos[i].empty()) continue;
        int maxi = 0;
        for(int j=0;j<pos[i].size() - 1;j++) {
            maxi = max(maxi, pos[i][j+1] - pos[i][j]);
        }
        maxi = max(maxi, n - pos[i].back() + 1);
        maxi = max(maxi, pos[i][0]);
        ans[maxi] = min(ans[maxi], i);
    }
    for(int i=2;i<=n;i++) {
        ans[i] = min(ans[i], ans[i-1]);
    }
    for(int i=1;i<=n;i++) cout << (ans[i] == inf ? -1 : ans[i]) << " ";
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