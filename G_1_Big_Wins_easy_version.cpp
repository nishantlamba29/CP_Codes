#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> table;
int query(int l, int r) {
    int cnt = (r - l + 1);
    int k = __lg(cnt);
    return min(table[k][l], table[k][r - (1 << k) + 1]);
}

struct SegTree {
    int len;
    vector<int> t;

    SegTree(int n) {
        len = n;
        t.assign(2 * len, INT_MAX); // initialize with INT_MAX
    }

    void update(int id, int val) {
        id += len;                 // move to leaf
        t[id] = min(t[id], val);   // update leaf value

        // propagate up
        for (id >>= 1; id > 0; id >>= 1)
            t[id] = min(t[id << 1], t[id << 1 | 1]);
    }

    int query(int l, int r) {
        int res = INT_MAX;
        l += len;
        r += len;
        while (l <= r) {
            if (l & 1) res = min(res, t[l++]);
            if (!(r & 1)) res = min(res, t[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int LOG = __lg(n) + 1;
    table.assign(LOG, vector<int>(n));
    table[0] = v;
    for(int j=1;j<LOG;j++) {
        for(int i=0;(i + (1 << j)) <= n;i++) {
            table[j][i] = min(table[j-1][i], table[j-1][i + (1 << (j - 1))]);
        }
    }
    int ans = 0;
    for(int med = 1; med <= 100; med++) {
        SegTree sg(2 * n + 1);
        sg.update(n, 0); // pre[0] = 0
        vector<int> pre(n+1);
        for(int i=0;i<n;i++) {
            pre[i+1] = (v[i] >= med) - (v[i] < med);
        }
        
        for(int i=1;i<=n;i++) {
            pre[i] += pre[i-1];
            int new_val = pre[i] + n;
            // l to r subarray
            // finding l such that pre[r] - pre[l-1] >= 0
            int l = sg.query(0, new_val); // l - 1
            if(l != INT_MAX) {
                int mini = query(l, i - 1); // l = l - 1 so...
                ans = max(ans, med - mini);
            }
            sg.update(new_val, i);
        }
    }

    cout << ans << "\n";


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}