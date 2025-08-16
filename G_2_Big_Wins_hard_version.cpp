#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> pos[N];

struct node {
    int pref;
    int suff;
    int max_sum;
    int total_sum;
    int mini;
};

node merge(node left, node right) {
    node ans;
    ans.total_sum = left.total_sum + right.total_sum;
    ans.pref = max(left.pref, left.total_sum + right.pref);
    ans.suff = max(right.suff, left.suff + right.total_sum);
    ans.max_sum = max({left.suff + right.pref, left.max_sum, right.max_sum});
    ans.mini = min(left.mini, right.mini);
    return ans;
}

int MED;
int ans = 0;

class SegTree {
public:
    int len;
    vector<node> t;

    SegTree(int l) {
        len = l;
        t.resize(4 * len);
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = node(0, 0, 0, -1, a[tl]);
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, (v << 1) + 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[(v << 1) + 1]);
        return;
    }

    void update(int v, int tl, int tr, int id) {
        if (tl == id && tr == id) {
            t[v].pref = t[v].suff = t[v].total_sum = t[v].max_sum = 1;
            return;
        }
        if (id < tl || id > tr) return;
        int tm = (tl + tr) >> 1;
        if(id <= tm) {
            update(v << 1, tl, tm, id);
        }
        else {
            update(v << 1 | 1, tm + 1, tr, id);
        }
        
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
        if(t[v].total_sum >= 0) {
            ans = max(ans, MED - t[v].mini);
        }
        else {
            // mini such that max_suff + pre(from right) >= 0
            int mini = query_pref(v << 1 | 1, tm + 1, tr, t[v << 1].suff);

            if(mini != INT_MAX) {
                ans = max(ans, MED - mini);
            }

            mini = query_suff(v << 1, tl, tm, t[v << 1 | 1].pref);
            if(mini != INT_MAX) {
                ans = max(ans, MED - mini);
            }
        }
        return;
    }
    
    int query_suff(int v, int tl, int tr, int val) {
        if(tl == tr) {
            if(val + t[v].total_sum < 0) return INT_MAX;
            return t[v].mini;
        }
        if(t[v].total_sum + val >= 0) return t[v].mini;
        int tm = (tl + tr) >> 1;
        if(val + t[v << 1 | 1].total_sum >= 0) {
            int m1 = query_suff(v << 1, tl, tm, val + t[v << 1 | 1].total_sum);
            return min(m1, t[v << 1 | 1].mini);
        }
        else {
            return query_suff(v << 1 | 1, tm + 1, tr, val);
        }
    }

    int query_pref(int v, int tl, int tr, int val) {
        if(tl == tr) {
            if(val + t[v].total_sum < 0) return INT_MAX;
            return t[v].mini;
        }
        if(t[v].total_sum + val >= 0) return t[v].mini;
        int tm = (tl + tr) >> 1;
        if(val + t[v << 1].total_sum >= 0) {
            return min(t[v << 1].mini, query_pref(v << 1 | 1, tm + 1, tr, val + t[v << 1].total_sum));
        }
        else {
            return query_pref(v << 1, tl, tm, val);
        }
    }

    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }

    void update(int id) {
        update(1, 0, len - 1, id);
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin >> _;
    while (_-->0) {

        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<=n;i++) pos[i].clear();

        for(int i=0;i<n;i++) {
            cin >> v[i];
            pos[v[i]].push_back(i);
        }

        SegTree sg(n);
        sg.build(v);
        ans = 0;
        for(int med = n; med > 0; med--) {
            if(pos[med].empty()) continue;
            for(int j : pos[med]) {
                MED = med;
                sg.update(j);
            }
        }

        cout << ans << "\n";

    }


    return 0;
}