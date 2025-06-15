#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

class SegmentTree {
private:
    int len;
    vector<int> t;
    void build(vector<int> &a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
            return; 
        }
        int tm = (tl + tr) >> 1LL;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
    void update(int v, int tl, int tr, int id, int val) {
        if(tl == id && tr == id) {
            t[v] = val;
            return;
        }
        if(id > tr || id < tl) return;
        int tm = (tl + tr) >> 1LL;
        update(v << 1, tl, tm, id, val);
        update(v << 1 | 1, tm + 1, tr, id, val);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(tl > r || tr < l) return inf;
        if(l <= tl && r >= tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1LL;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return min(left, right);
    }
public:    
    SegmentTree() {}
    SegmentTree(int l) {
        len = l;
        t.resize(4 * len);
    }
    SegmentTree(vector<int> &a) {
        len = a.size();
        t.resize(4 * len);
        vector<int> temp = a;
        build(temp, 1, 0, len - 1);
    }
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }
    void update(int id, int val) {
        update(1, 0, len - 1, id, val);
    }
    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
    }
};

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    SegmentTree sg(v);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k, u;
            cin >> k >> u;
            sg.update(k - 1, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << sg.query(a - 1, b - 1) << "\n";
        }
    }
    return 0;
}