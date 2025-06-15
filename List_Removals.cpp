#include <bits/stdc++.h>
using namespace std;

class SegTree {
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
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
    void update(int v, int tl, int tr, int id, int val) {
        if(id < tl || id > tr) return;
        if(tl == id && tr == id) {
            t[v] = val;
            return;
        }
        int tm = (tl + tr) >> 1LL;
        update(v << 1, tl, tm, id, val);
        update(v << 1 | 1, tm + 1, tr, id, val);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
    int query(int v, int tl, int tr, int val) {
        if(tl == tr) return tl;
        int tm = (tl + tr) >> 1LL;
        if(t[v << 1] >= val) {
            return query(v << 1, tl, tm, val);
        }
        else return query(v << 1 | 1, tm + 1, tr, val - t[v << 1]); // right jaa rha hu toh left wala minus
    }
public:
    SegTree(int l) {
        len = l;
        t.resize(4 * len);
    }
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }
    void update(int id, int val) {
        update(1, 0, len - 1, id, val);
    }
    int query(int val) {
        return query(1, 0, len - 1, val);
    }
};

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> vis(n, 1);

    SegTree sg(n);
    sg.build(vis);

    for(int i=0;i<n;i++) {
        int p;
        cin >> p;
        int ind = sg.query(p);
        cout << v[ind] << " ";
        sg.update(ind, 0);
    }


    return 0;
}