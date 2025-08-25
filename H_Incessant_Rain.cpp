#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;
vector<int> pos[N], pos2[N];
vector<array<int, 3>> time_stamp[N];
vector<array<int, 2>> changes[N];
multiset<int> st;

struct node {
    int sum;
    int pre;
    int suff;
    int maxi;
    bool isValid = 0;
    node(){}
    node(int s, int p, int su, int m) {
        sum = s;
        pre = p;
        suff = su;
        maxi = m;
        isValid = 1;
    }
};

node merge(node &left, node &right) {
    if(!left.isValid) return right;
    if(!right.isValid) return left;
    node ans;
    ans.sum = left.sum + right.sum;
    ans.pre = max(left.pre, left.sum + right.pre);
    ans.suff = max(right.suff, left.suff + right.sum);
    ans.maxi = max({left.maxi, right.maxi, left.suff + right.pre});
    ans.isValid = 1;
    return ans;
}

class SegTree {
public:
    int len;
    vector<node> t;

    SegTree(int l) {
        len = l;
        t.resize(4 * len);
        build(1, 0, len - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            int val = -1;
            t[v] = {val, max(0, val), max(0, val), max(0, val)};
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v <<1 | 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int id, int val) {
        if (tl == id && tr == id) {
            t[v] = {val, max(0, val), max(0, val), max(0, val)};
            return;
        }
        if (id < tl || id > tr) return;
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, id, val);
        update((v << 1) + 1, tm + 1, tr, id, val);
        t[v] = merge(t[v << 1], t[(v << 1) + 1]);
    }

    node query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return node();
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) >> 1;
        node left = query(v << 1, tl, tm, l, r);
        node right = query((v << 1) + 1, tm + 1, tr, l, r);
        return merge(left, right);
    }

    void update(int id, int val) {
        update(1, 0, len - 1, id, val);
    }

    int query(int l, int r) {
        return query(1, 0, len - 1, l, r).maxi;
    }
};

inline void n_lamba_29() {

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<=n;i++) {
        time_stamp[i].clear();
        pos[i].clear();
        pos2[i].clear();
    }
    for(int i=0;i<n;i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    SegTree sg(n);

    vector<array<int,2>> query;
    vector<int> temp = v;
    st.clear();

    for(int i=0;i<q;i++) {
        changes[i].clear();
        int j, x;
        cin >> j >> x;
        j--;
        query.push_back({j, x});
        if(temp[j] == x) {
            continue;
        }

        int old = temp[j];
        temp[j] = x;

        time_stamp[old].push_back({j, i, -1});
        time_stamp[x].push_back({j, i, 1});

    }

    for(int i=0;i<n;i++) {
        pos2[temp[i]].push_back(i);
    }
    
    for(int i = 1; i<= n; i++) {
        for(int j : pos[i]) {
            sg.update(j, 1);
        }
        int val = sg.query(0, n - 1) / 2; // initial majority just before its first update
        st.insert(val);
        for(auto [j, ind, type] : time_stamp[i]) {
            sg.update(j, type);
            int val1 = sg.query(0, n - 1) / 2; // current majority after update at ind time stamp
            changes[ind].push_back({val, val1});
            val = val1;
        }

        for(int j : pos2[i]) {
            sg.update(j, -1);
        }

    }

    for(int i=0;i<q;i++) {
        for(auto [to_remove, to_add] : changes[i]) {
            st.erase(st.find(to_remove));
            st.insert(to_add);
        }
        auto it = st.end();
        int ans = *prev(it);
        cout << ans << " ";
    }
    cout << "\n";

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}