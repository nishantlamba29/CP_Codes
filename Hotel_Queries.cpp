#include <bits/stdc++.h>
using namespace std;
#define int long long

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
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
    void update(int v, int tl, int tr, int id, int val) {
        if(id < tl || id > tr) return;
        if(tl == id && tr == id) {
            t[v] += val;
            return;
        }
        int tm = (tl + tr) >> 1LL;
        update(v << 1, tl, tm, id, val);
        update(v << 1 | 1, tm + 1, tr, id, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
    int query(int v, int tl, int tr, int val) {
        if(t[v] < val) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) >> 1LL;
        if(t[v << 1] >= val) {
            return query(v << 1, tl, tm, val);
        }
        else {
            return query(v << 1 | 1, tm + 1, tr, val);
        }
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

    int n, m;
    cin >> n >> m;
    vector<int> h(n);

    for(int i=0;i<n;i++) cin >> h[i];
    
    SegTree sg(n);
    sg.build(h);
    
    for(int i=0;i<m;i++) {
        int r;
        cin >> r;
        int ind = sg.query(r);
        if(ind == -1) {
            cout << "0 ";
            continue;
        }
        cout << ind + 1 << " ";
        sg.update(ind, -r);
    }

    return 0;
}