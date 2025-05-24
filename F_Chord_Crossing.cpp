#include <bits/stdc++.h>
using namespace std;
#define int long long

class Fenwick {
    int n;
    vector<int> bit;
    public:
    Fenwick(int n) {
        this->n = n;
        bit.resize(n+2, 0);
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

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end());

    int q;
    cin >> q;
    vector<array<int,3>> query(q);
    for(int i=0;i<q;i++) {
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end());
    Fenwick f(2*n), f1(2*n), f2(2*n);
    for(auto &[a, b] : v) {
        f1.update(a, 1);
        f2.update(b, 1);
    }

    vector<int> res(q);
    int j = 0;
    for(auto &[st, end, ind] : query) {
        while(j < m && v[j].first <= st) {
            f.update(v[j].second, 1);
            j++;
        }
        int both = j - f.query(end - 1);
        res[ind] = f1.query(st) - f2.query(st) + f1.query(end) - f2.query(end) - 2 * both;
    }

    for(auto i : res) cout << i << "\n";

    return 0;
}