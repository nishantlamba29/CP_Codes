#include <bits/stdc++.h>
using namespace std;

struct Q {
    char type;
    int a, b;
};

class Fenwick {
public:
    int n;
    vector<int> bit;
    Fenwick(int _n) {
        n = _n + 1;
        bit.resize(n+1, 0);
    }
    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }
    int query(int id) {
        int res = 0;
        while(id > 0) {
            res += bit[id];
            id -= id & -id;
        }
        return res;
    }
};

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    vector<int> total(v.begin(), v.end());

    vector<Q> qu(q);
    for(int i=0;i<q;i++) {
        cin >> qu[i].type >> qu[i].a >> qu[i].b;
        if(qu[i].type == '!') {
            total.push_back(qu[i].b);
        }
    }

    sort(total.begin(), total.end());
    total.erase(unique(total.begin(), total.end()), total.end());

    Fenwick f(total.size());

    for(int i=0;i<n;i++) {
        int ind = lower_bound(total.begin(), total.end(), v[i]) - total.begin();
        f.update(ind + 1, 1);
    }

    for(auto [type, a, b] : qu) {
        if(type == '?') {
            int hi = upper_bound(total.begin(), total.end(), b) - total.begin();
            int lo = lower_bound(total.begin(), total.end(), a) - total.begin();
            int ans = f.query(hi) - f.query(lo);
            cout << ans << "\n";
        }
        else {
            int k = a - 1;
            int old = v[k];
            int old_idx = lower_bound(total.begin(), total.end(), old) - total.begin();
            f.update(old_idx + 1, -1);
            v[k] = b;
            int new_idx = lower_bound(total.begin(), total.end(), v[k]) - total.begin();
            f.update(new_idx + 1, 1);
        }
    }

    return 0;
}