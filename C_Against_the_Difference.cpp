#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int inf = 1e9;
vector<int> pos[N];

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for(int i=0;i<=n;i++) {
        pos[i].clear();
    }

    for(int i=1;i<=n;i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    vector<array<int, 3>> I;
    I.push_back({-inf, -inf, 0});
    for(int i=1;i<=n;i++) {
        if(pos[i].empty() || pos[i].size() < i) continue;

        for(int j=0;i+j-1 < pos[i].size(); j++) {
            I.push_back({pos[i][j], pos[i][i+j-1], i});
        }

    }

    if(I.size() == 1) {
        cout << "0\n";
        return;
    }
    int sz = I.size();

    sort(I.begin(), I.end(), [&](auto &a, auto &b) {
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    vector<int> temp;
    for(int i=0;i<sz;i++) {
        temp.push_back(I[i][1]);
    }

    vector<int> dp(sz + 1);
    for(int i=1;i<sz;i++) {
        dp[i] = dp[i-1];
        int ind = upper_bound(temp.begin(), temp.begin() + i, I[i][0] - 1) - temp.begin() - 1;
        dp[i] = max(dp[i], dp[ind] + I[i][2]);
    }

    cout << dp[sz - 1] << "\n";

}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _; 
    if(!(cin >> _)) return 0;
    while (_-->0) {
        n_lamba_29();
    }

    return 0;
}
