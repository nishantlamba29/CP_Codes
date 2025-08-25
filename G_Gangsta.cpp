#include <bits/stdc++.h>
using namespace std;
#define int long long

class Fenwick {
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

    int query(int l, int r) {
        return query(r) - query(l-1);
    }
};

// F_Unjust_Binary_Life

inline void n_lamba_29() {
    int n;
    string s;
    cin >> n >> s;
    
    s = '#' + s;
    int cnt = 0;
    vector<int> f(n + 1);
    int ans = 0, k = n;

    for(int i=1;i<=n;i++) {
        ans += i * (k--);
        cnt += (s[i] == '0') - (s[i] == '1');
        f[i] = cnt;
    }

    int MAX = 4 * n;
    int offset = n + 1;
    Fenwick fen1(MAX), fen2(MAX);

    fen1.update(offset, 1); // count of f[l] < f[r]
    fen2.update(offset, 0); // sum of f[l] < f[r]

    for(int r = 1; r <= n; r++) {

        int c1 = fen1.query(f[r] + offset - 1);
        int sum1 = fen2.query(f[r] + offset - 1);
        int pos = (c1 * f[r]) - sum1;

        int c2 = fen1.query(f[r] + offset + 1, MAX);
        int sum2 = fen2.query(f[r] + offset + 1, MAX);
        int neg = sum2 - (c2 * f[r]);

        ans += pos + neg;

        fen1.update(f[r] + offset, 1);
        fen2.update(f[r] + offset, f[r]);

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