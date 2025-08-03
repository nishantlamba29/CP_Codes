#include <bits/stdc++.h>
using namespace std;

struct WaveletTree {
    int lo, hi;
    WaveletTree *l, *r;
    vector<int> b;  // b[i] = # elements from [0..i) going to left

    // Build over the range [from, to), with values in [x..y]
    WaveletTree(int *from, int *to, int x, int y)
        : lo(x), hi(y), l(nullptr), r(nullptr)
    {
        if (from >= to || lo == hi) return;
        int mid = (lo + hi) >> 1;
        auto f = [mid](int v){ return v <= mid; };
        b.reserve((to - from) + 1);
        b.push_back(0);
        for (auto it = from; it != to; ++it)
            b.push_back(b.back() + f(*it));
        auto pivot = stable_partition(from, to, f);
        l = new WaveletTree(from, pivot, lo, mid);
        r = new WaveletTree(pivot, to, mid+1, hi);
    }

    // Count of values in positions [lq..rq] that are <= k
    int LTE(int lq, int rq, int k) {
        if (lq > rq || k < lo) return 0;
        if (hi <= k) return rq - lq + 1;
        int lb = b[lq], rb = b[rq+1];
        return l->LTE(lb, rb-1, k)
             + r->LTE(lq - lb, rq - rb, k);
    }

    // Point-update: position idx had prev_val, now has new_val
    void update(int idx, int prev_val, int new_val) {
        if (lo == hi) return;
        int mid = (lo + hi) >> 1;
        bool wentLeft  = prev_val  <= mid;
        bool goesLeft  = new_val    <= mid;
        // If it crosses the boundary, adjust the prefix sums
        if (wentLeft != goesLeft) {
            for (int i = idx+1; i < (int)b.size(); ++i)
                b[i] += (goesLeft ? +1 : -1);
        }
        int leftCount = b[idx];
        // Recurse into the child it belonged to originally
        if (wentLeft)
            l->update(leftCount, prev_val, new_val);
        else
            r->update(idx - leftCount, prev_val, new_val);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n), coord;
    coord.reserve(n + q);

    // Read initial array
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        coord.push_back(v[i]);
    }

    // Read queries
    vector<array<int,3>> queries(q);
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> a >> b;
        t = 2;
        queries[i] = {t, a, b};
        if (t == 1) {
            // updates introduce new values to compress
            coord.push_back(b);
        }
    }

    // Coordinate-compress
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    auto getId = [&](int x){
        return int(lower_bound(coord.begin(), coord.end(), x) - coord.begin());
    };

    for (int &x : v)
        x = getId(x);
    for (auto &qq : queries) {
        if (qq[0] == 1)
            qq[2] = getId(qq[2]);
    }

    // Build next_pos[]
    vector<int> next_pos(n), last(coord.size(), n);
    for (int i = n-1; i >= 0; --i) {
        next_pos[i] = last[v[i]];
        last[v[i]] = i;
    }

    // Build wavelet tree over next_pos in [0..n]
    WaveletTree wt(next_pos.data(), next_pos.data() + n, 0, n);

    // Track positions of each value for update bookkeeping
    vector<set<int>> pos(coord.size());
    for (int i = 0; i < n; i++)
        pos[v[i]].insert(i);

    // Process queries
    for (auto &qq : queries) {
        int type = qq[0], a = qq[1], b = qq[2];
        if (type == 1) {
            // Update A[a] = new_val
            int idx     = a - 1;
            int old_val = v[idx];
            int new_val = b;
            if (old_val == new_val) continue;

            // --- remove idx from old_val's list
            {
                auto &st = pos[old_val];
                auto it  = st.find(idx);
                int nxt = n, prv = -1;
                if (std::next(it) != st.end())   nxt = *(std::next(it));
                if (it != st.begin())       prv = *(std::prev(it));

                // link prv → nxt
                if (prv != -1) {
                    wt.update(prv, next_pos[prv], nxt);
                    next_pos[prv] = nxt;
                }
                st.erase(it);
            }

            // --- insert idx into new_val's list
            {
                auto &st = pos[new_val];
                st.insert(idx);
                auto it  = st.find(idx);
                int nxt = n, prv = -1;
                if (std::next(it) != st.end())   nxt = *(std::next(it));
                if (it != st.begin())       prv = *(std::prev(it));

                // link prv → idx
                if (prv != -1) {
                    wt.update(prv, next_pos[prv], idx);
                    next_pos[prv] = idx;
                }
                // set idx → nxt
                wt.update(idx, next_pos[idx], nxt);
                next_pos[idx] = nxt;
            }

            // finally update the array
            v[idx] = new_val;
        }
        else {
            // Query distinct in [a..b]
            int l = a - 1, r = b - 1;
            int length = r - l + 1;
            int cntLE  = wt.LTE(l, r, r);
            // distinct = total - (# of next_pos ≤ r)
            cout << (length - cntLE) << "\n";
        }
    }
    return 0;
}
