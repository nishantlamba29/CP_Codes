#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

class SparseTable {
    int n;
    int LOG;
    vector<vector<int>> table;
    vector<int> lg2;
    public:
    SparseTable(){}
    void build(vector<int> &v) {
        n = v.size();
        LOG = __lg(n) + 1;
        table.resize(LOG, vector<int>(n));
        lg2.resize(n + 1);
        lg2[1] = 0;
        for(int i=2;i<=n;i++) lg2[i] = lg2[i >> 1] + 1;
        table[0] = v;
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; (i + (1 << j)) <= n; i++) {
                table[j][i] = gcd(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int query(int l, int r) {
        if(l > r) return 0;
        int k = lg2[r - l + 1];
        return gcd(table[k][l], table[k][r - (1 << k) + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    if(n == 1) {
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << "0 ";
        }
        cout << "\n";
        return;
    }

    vector<int> d(n-1);
    for(int i=0;i<n-1;i++) d[i] = abs(v[i+1] - v[i]);

    SparseTable st;
    st.build(d);

    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l == r) cout << "0 ";
        else cout << st.query(l, r - 1) << " ";
    }
    cout << "\n";


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}