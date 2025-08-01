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
            unprop[v] = val;
        }
        t[v] = (tr - tl + 1) * val;
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
        t[v] = t[v << 1] + t[v << 1 | 1];
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
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
    
    int query(int v, int tl, int tr, int l, int r) {
        if(r < tl || l > tr) return 0;
        if(l <= tl && tr <= r) {
            return t[v];
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return left + right;
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

    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    
    vector<int> pre = x;
    for(int i=1;i<n;i++) pre[i] += pre[i-1];

    stack<int> st;
    vector<int> nge(n, n);
    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && x[i] > x[st.top()]) {
            st.pop();
        }
        if(!st.empty()) nge[i] = st.top();
        st.push(i);
    }

    SegTree sg(n);

    vector<pair<int,int>> query[n];
    for(int i=0;i<q;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        query[a].push_back({b, i});
    }

    vector<int> ans(q);
    for(int i=n-1;i>=0;i--) {
        sg.update(i, nge[i] - 1, x[i]);
        for(auto [r, index] : query[i]) {
            ans[index] = sg.query(i, r) - (pre[r] - (i > 0 ? pre[i-1] : 0));
        }
    }
    for(int i=0;i<q;i++) cout << ans[i] << "\n";

    return 0;
}