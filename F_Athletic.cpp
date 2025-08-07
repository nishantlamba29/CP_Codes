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

    int n, d, r;
    cin >> n >> d >> r;
    vector<int> h(n);
    vector<int> inv(n + 1);
    for(int i=0;i<n;i++) {
        cin >> h[i];
        inv[h[i]] = i;
    }

    SegTree sg(n);
    vector<int> dp(n);
    int ans = 0;

    for(int i=1;i<=n;i++) {
        int ind = inv[i];
        if(i - d > 0) {
            int ind2 = inv[i-d];
            sg.update(ind2, dp[ind2]);
        }
        int t1 = sg.query(max(0LL, ind - r), min(n-1, ind + r));
        dp[ind] = 1 + t1;
        ans = max(ans, dp[ind]);
    }

    cout << max(0LL, ans - 1);

    return 0;
}