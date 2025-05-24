#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> bit(n+1, 0);
    auto update = [&](int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    };
    auto query = [&](int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= id & -id;
        }
        return ans;
    };

    for(int i=0;i<n;i++) {
        update(i+1, v[i]);
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int ind, val;
            cin >> ind >> val;
            update(ind, val - v[ind - 1]);
            v[ind - 1] = val;
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(b) - query(a - 1) << "\n";
        }
    }

    return 0;
}