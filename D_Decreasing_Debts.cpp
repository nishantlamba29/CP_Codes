#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> bal(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        bal[u] += w;
        bal[v] -= w;
    }

    vector<array<int,3>> ans;
    vector<pair<int,int>> pos, neg;
    for(int i=1;i<=n;i++) {
        if(bal[i] > 0) {
            pos.push_back({i, bal[i]});
        }
        else if(bal[i] < 0) {
            neg.push_back({i, -bal[i]});
        }
    }

    int lo = 0;
    for(int i=0;i<pos.size();i++) {
        while(pos[i].second > 0) {
            int z = min(pos[i].second, neg[lo].second);
            pos[i].second -= z;
            neg[lo].second -= z;
            ans.push_back({pos[i].first, neg[lo].first, z});
            if(neg[lo].second == 0) {
                lo++;
            }
        }
    }

    cout << ans.size() << "\n";
    for(auto [u, v, w] : ans) cout << u << " " << v << " " << w << "\n";

    return 0;
}