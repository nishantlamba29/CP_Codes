#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e17;

class SegTree {
private:
    int len;
    vector<int> t, unprop;
    vector<bool> isLazy;

    void apply(int v, int tl, int tr, int val) {
        if(tl != tr) {
            isLazy[v] = 1;
            unprop[v] += val;
        }
        t[v] += val;
    }

    void push_down(int v, int tl, int tr) {
        if(!isLazy[v]) return;
        isLazy[v] = 0;
        int tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, unprop[v]);
        apply(v << 1 | 1, tm + 1, tr, unprop[v]);
        unprop[v] = 0;
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

    void update(int v, int tl, int tr, int l, int r, int val) {
        if(r < tl || l > tr) return;
        if(l <= tl && tr <= r) {
            apply(v, tl, tr, val);
            return;
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, l, r, val);
        update(v << 1 | 1, tm + 1, tr, l, r, val);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
    
    int query(int v, int tl, int tr, int l, int r) {
        if(r < tl || l > tr) return inf;
        if(l <= tl && tr <= r) {
            return t[v];
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return min(left, right);
    }
    
public:
    SegTree(int _n) {
        len = _n;
        t.resize(4 * len);
        unprop.resize(4 * len);
        isLazy.resize(4 * len);
    }
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }
    void update(int l, int r, int val) {
        update(1, 0, len - 1, l, r, val);
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
    vector<int> v(n, 0);
    SegTree sg(n);
    sg.build(v);

    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            r--;
            sg.update(l, r, val);
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