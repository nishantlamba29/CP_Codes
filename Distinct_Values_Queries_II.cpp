#include <bits/stdc++.h>
using namespace std;

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

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> temp;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        temp.push_back(v[i]);
    }
    vector<array<int,3>> query(q);
    for(int i=0;i<q;i++) {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
        if(query[i][0] == 1) {
            query[i][1]--;
            temp.push_back(query[i][2]);
        }
        else {
            query[i][1]--;
            query[i][2]--;
        }
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    int sz = temp.size();

    for(auto &ele : v) {
        ele = lower_bound(temp.begin(), temp.end(), ele) - temp.begin();
    }
    for(auto &[type, a, b] : query) {
        if(type == 1) {
            b = lower_bound(temp.begin(), temp.end(), b) - temp.begin();
        }
    }

    vector<int> next_pos(n);
    vector<int> prev(sz+1, n);
    for(int i=n-1;i>=0;i--) {
        next_pos[i] = prev[v[i]];
        prev[v[i]] = i;
    }

    SegTree sg(n);
    sg.build(next_pos);

    vector<set<int>> pos(sz+1);
    for(int i=0;i<n;i++) {
        pos[v[i]].insert(i);
    }

    for(auto [type, a, b] : query) {
        if(type == 1) {
            int ind = a;
            int old_val = v[ind];
            int new_val = b;
            if(old_val == new_val) continue;
            // remove
            {
                auto &st = pos[old_val];
                auto it = st.find(ind);
                int next = n, prev = -1;
                if(std::next(it) != st.end()) {
                    next = *(std::next(it));
                }
                if(it != st.begin()) {
                    prev = *(std::prev(it));
                }
                if(prev != -1) {
                    next_pos[prev] = next;
                    sg.update(prev, next);
                }
                st.erase(it);
            }
            // add
            {
                auto &st = pos[new_val];
                st.insert(ind);
                auto it = st.find(ind);
                int next = n, prev = -1;
                if(std::next(it) != st.end()) {
                    next = *(std::next(it));
                }
                if(it != st.begin()) {
                    prev = *(std::prev(it));
                }
                if(prev != -1) {
                    next_pos[prev] = ind;
                    sg.update(prev, ind);
                }
                next_pos[ind] = next;
                sg.update(ind, next);
            }
            v[ind] = new_val;
        }
        else {
            int mn = sg.query(a, b);
            if(mn > b) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}