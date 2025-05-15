#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> table;

void build(int n, vector<int> v) {
    table[0] = v;
    for(int j=1;j<21;j++) {
        for(int i=0;(i+(1<<j))<=n;i++) {
            table[j][i] = min(table[j-1][i], table[j-1][i + (1<<(j-1))]);
        }
    }
}

int query(int l, int r) {
    int cnt = (r - l + 1);
    int k = __lg(cnt);
    return min(table[k][l], table[k][r - (1<<k) + 1]);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    table.resize(21, vector<int>(n));
    build(n, v);

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }


    return 0;
}