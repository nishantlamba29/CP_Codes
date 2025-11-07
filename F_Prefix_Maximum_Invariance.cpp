#include <bits/stdc++.h>
using namespace std;
#define int long long
class SegTree {
public:
    int len;
    vector<int> t;

    SegTree(int l) {
        len = l;
        t.resize(4 * len);
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, (v << 1) + 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
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
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query((v << 1) + 1, tm + 1, tr, l, r);
        return max(left, right);
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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    SegTree sg(n);
    sg.build(a);
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == b[i]) {
            ans += (i + 1) * (n - i);
        }
        else {
            int lo = 0, hi = i-1;
            int cnt_left = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(sg.query(mid, i-1) >= max(a[i], b[i])) {
                    cnt_left = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            ans += (cnt_left + 1) * (n - i);
        }
    }

    cout << ans << "\n";

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