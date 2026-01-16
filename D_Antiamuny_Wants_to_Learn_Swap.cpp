#include <bits/stdc++.h>
using namespace std;

int n;
class SegTree {
public:
    int len;
    vector<int> t;

    SegTree(int l) {
        len = l;
        t.resize(4 * len, n);
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, (v << 1) + 1, tm + 1, tr);
        t[v] = min(t[v << 1], t[(v << 1) + 1]);
    }

    void update(int v, int tl, int tr, int id, int val) {
        if (tl == id && tr == id) {
            t[v] = val;
            return;
        }
        if (id < tl || id > tr) return;
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, id, val);
        update((v << 1) + 1, tm + 1, tr, id, val);
        t[v] = min(t[v << 1], t[(v << 1) + 1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return INT_MAX;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query((v << 1) + 1, tm + 1, tr, l, r);
        return min(left, right);
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

inline void n_lamba_29() {

    int q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> pos(n + 1);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--) {
        while(st.size() && v[st.top()] > v[i]) {
            st.pop();
        }
        if(st.size()) nse[i] = st.top();
        else nse[i] = n;
        st.push(i);
    }
    
    SegTree sg(n);
    vector<int> help(n, n);
    for(int j=1;j<=n;j++) {
        int ind = pos[j];
        int mini = sg.query(ind, n - 1);
        help[ind] = mini;
        sg.update(ind, nse[ind]);
    }
    SegTree sg1(n);
    sg1.build(help);

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int mini = sg1.query(l, r);
        if(mini <= r) cout << "NO\n";
        else cout << "YES\n";

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