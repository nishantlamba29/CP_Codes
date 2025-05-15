#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> table;

void build(int n, vector<int> v) {
    table[0] = v;
    for(int j=1;j<22;j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            table[j][i] = min(table[j-1][i], table[j-1][i + (1 << (j-1))]);
        }
    }
}

int query(int l, int r) {
    int k = __lg(r - l + 1);
    return min(table[k][l], table[k][r - (1 << k) + 1]);
}

inline void n_lamba_29() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    table.resize(22, vector<int>(n));
    build(n, v);

    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << query(a, b) << "\n";
    }
}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();
    
    return 0;
}