#include <bits/stdc++.h>
using namespace std;
#define int long long 
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
        t[v] += (tr - tl + 1) * val;
    }
    void pushDown(int v, int tl, int tr) {
        if(!isLazy[v]) return;
        isLazy[v] = 0;
        int tm = (tl + tr) >> 1LL;
        apply(v << 1, tl, tm, unprop[v]);
        apply(v << 1 | 1, tm + 1, tr, unprop[v]);
        unprop[v] = 0;
    }
    void build(vector<int> &a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1LL;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int val) {
        if(l > tr || r < tl) return;
        if(l <= tl && r >= tr) {
            apply(v, tl, tr, val);
            return;
        }
        pushDown(v, tl, tr);
        int tm = (tl + tr) >> 1LL;
        update(v << 1, tl, tm, l, r, val);
        update(v << 1 | 1, tm + 1, tr, l, r, val);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
    int query(int v, int tl, int tr, int id) {
        if(tl == id && tr == id) {
            return t[v];
        }
        pushDown(v, tl, tr);
        int tm = (tl + tr) >> 1LL;
        if(id <= tm) return query(v << 1, tl, tm, id);
        else return query(v << 1 | 1, tm + 1, tr, id);
    }
public:
    SegTree(vector<int> &a) {
        len = a.size();
        t.resize(4 * len);
        isLazy.resize(4 * len);
        unprop.resize(4 * len);
        vector<int> temp = a;
        build(temp);
    }
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }
    void update(int l, int r, int val) {
        update(1, 0, len - 1, l, r, val);
    }
    int query(int id) {
        return query(1, 0, len - 1, id);
    }
};
 
int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
 
    SegTree sg(v);
 
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            sg.update(a - 1, b - 1, u);
        }
        else {
            int k;
            cin >> k;
            cout << sg.query(k - 1) << "\n";
        }
    }

    return 0;
}