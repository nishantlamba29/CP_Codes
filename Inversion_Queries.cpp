#include <bits/stdc++.h>
using namespace std;
#define int long long

class Fenwick{
    int n;
    vector<int> bit;
    public:
    Fenwick(int n) {
        this->n = n;
        bit = vector<int>(n+1, 0);
    }
    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }
    int query(int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= id & -id;
        }
        return ans;
    }
};

inline void n_lamba_29() {

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Fenwick f1(n), f2(n);

    vector<int> pre1(n+1, 0); // inversion smaller to right
    vector<int> pre2(n+1, 0); // inversion greater to left
    for(int i=n-1;i>=0;i--) {
        pre1[v[i]] = f1.query(v[i] - 1);
        f1.update(v[i], 1);
    }
    for(int i=0;i<n;i++) {
        pre2[v[i]] = i - f2.query(v[i]);
        f2.update(v[i], 1);
    }

    for(int i=2;i<=n;i++) pre1[i] += pre1[i-1];
    for(int i=2;i<=n;i++) pre2[i] += pre2[i-1];

    int total = pre1[n];
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << "0\n";
            continue;
        }
        int right = pre1[l]; // L k right m jo smaller the unka inv count minus 
        int left = pre2[n] - pre2[r - 1]; // R k left m jo greater the unka minus (total - smaller wale)
        cout << total - left - right << "\n";
    }

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