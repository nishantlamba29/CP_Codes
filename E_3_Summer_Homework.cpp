#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9;
const int N = 2e5 + 5;

int fib[N], pfib[N];
pair<int,int> dp[N];

struct node {
    int p0, p1, len;
    bool isValid = false;
    node(){}
    node(int val) {
        p0 = val;
        p1 = val;
        len = 1;
        isValid = 1;
    }
};

node merge(node &left, node &right) {
    if(!left.isValid) return right;
    if(!right.isValid) return left;
    node ans;
    ans.p0 = ((left.p0 + dp[left.len].first * right.p0 % mod) % mod + dp[left.len].second * right.p1 % mod) % mod;
    ans.p1 = ((left.p1 + dp[left.len + 1].first * right.p0 % mod) % mod + dp[left.len + 1].second * right.p1 % mod) % mod;
    ans.len = left.len + right.len;
    ans.isValid = 1;
    return ans;
}

class SegTree {
private:
    int len;
    vector<node> t;
    vector<int> unprop;
    vector<bool> isLazy;

    void apply(int v, int tl, int tr, int val) {
        if(tl != tr) {
            isLazy[v] = 1;
            unprop[v] += val;
        }
        t[v].p0 = (t[v].p0 + (pfib[t[v].len - 1] * val) % mod) % mod;
        t[v].p1 = (t[v].p1 + ((pfib[t[v].len] - pfib[0]) * val) % mod) % mod;
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
            t[v] = node(a[tl]);
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int id, int val) {
        if(tr < id || tl > id) return;
        if(tl == id && tr == id) {
            t[v] = node(val);
            return;
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;

        update(v << 1, tl, tm, id, val);
        update(v << 1 | 1, tm + 1, tr, id, val);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
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
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
    
    node query(int v, int tl, int tr, int l, int r) {
        if(r < tl || l > tr) return node();
        if(l <= tl && tr <= r) {
            return t[v];
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        node left = query(v << 1, tl, tm, l, r);
        node right = query(v << 1 | 1, tm + 1, tr, l, r);
        return merge(left, right);
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
    void update(int ind, int val) {
        update(1, 0, len - 1, ind, val);
    }
    int query(int l, int r) {
        return query(1, 0, len - 1, l, r).p0;
    }
};


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    fib[0] = 1, fib[1] = 1;
    pfib[0] = 1, pfib[1] = 2;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for(int i=2;i<=n;i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
        pfib[i] = (pfib[i-1] + fib[i]) % mod;
        dp[i].first = (dp[i-1].first + dp[i-2].first) % mod;
        dp[i].second = (dp[i-1].second + dp[i-2].second) % mod;
    }

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    SegTree sg(n);
    sg.build(v);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int pos, val;
            cin >> pos >> val;
            pos--;
            sg.update(pos, val);
        }
        else if(type == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sg.query(l, r) << '\n';
        }
        else {
            int l, r, d;
            cin >> l >> r >> d;
            l--, r--;
            sg.update(l, r, d);
        }
    }

    return 0;
}