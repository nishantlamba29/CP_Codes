#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

class SegTree {
private:
    int len;
    vector<int> t, unprop;
    vector<bool> isLazy;

    void apply(int v, int tl, int tr, int val) {
        if(tl != tr) {
            isLazy[v] = 1;
            unprop[v] += val;
        }
        t[v] += val;
    }

    void push_down(int v, int tl, int tr) {
        if(!isLazy[v]) return;
        isLazy[v] = 0;
        int tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, unprop[v]);
        apply(v << 1 | 1, tm + 1, tr, unprop[v]);
        unprop[v] = 0;
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
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
    
    int query(int v, int tl, int tr, int l, int r) {
        if(r < tl || l > tr) return inf;
        if(l <= tl && tr <= r) {
            return t[v];
        }
        push_down(v, tl, tr);
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, r);
        int right = query(v << 1 | 1, tm + 1, tr, l, r);
        return min(left, right);
    }
    
public:
    SegTree(int _n) {
        len = _n;
        t.resize(4 * len);
        unprop.resize(4 * len);
        isLazy.resize(4 * len);
    }
    void update(int l, int r, int val) {
        update(1, 0, len - 1, l, r, val);
    }
    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
    }
};


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> temp;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
        temp.push_back(a[i]);
        temp.push_back(b[i]);
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i=0;i<n;i++) {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
        b[i] = lower_bound(temp.begin(), temp.end(), b[i]) - temp.begin();
    }

    int sz = temp.size();
    SegTree sg(sz + 1);

    for(int i=0;i<n;i++) {
        sg.update(0, a[i], 1);
        sg.update(0, b[i], -1);
    }

    if(sg.query(0, sz) < 0) {
        cout << "-1\n";
        return 0;
    }
    
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++) {
        if(a[i] >= b[i]) {
            arr.push_back({b[i] + 1, a[i]});
        }
    }
    sort(arr.rbegin(), arr.rend());

    int ans = 0;
    for(auto &[l, r] : arr) {
        if(sg.query(l, r) > 0) {
            ans++;
            sg.update(l, r, -1);
        }
    }

    cout << ans << "\n";

    return 0;
}