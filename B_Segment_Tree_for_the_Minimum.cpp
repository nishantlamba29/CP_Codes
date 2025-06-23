#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e17;

class SegTree {
public:
    int len;
    vector<int> t;
    SegTree(int _n) {
        len = _n;
        t.resize(4*len);
    }
    void build(vector<int> &a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }
    void update(int v, int tl, int tr, int id, int val) {
        if(tl == id && tr == id) {
            t[v] = val;
            return;
        }
        if(id < tl || id > tr) return;
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, id, val);
        update(v << 1 | 1, tm + 1, tr, id, val);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
    void update(int id, int val) {
        update(1, 0, len - 1, id, val);
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(l <= tl && tr <= r) return t[v];
        if(r < tl || tr < l) return inf;
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return min(left, right);
    }
    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
    }
};
int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    SegTree sg(n);
    sg.build(v);

    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int id, val;
            cin >> id >> val;
            sg.update(id, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            r--;
            cout << sg.query(l, r) << "\n";
        }
    }


    return 0;
}