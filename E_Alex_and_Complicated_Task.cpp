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
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }

    void update(int v, int tl, int tr, int id, int val) {
        if (tl == id && tr == id) {
            t[v] = max(t[v], val);
            return;
        }
        if (id < tl || id > tr) return;
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, id, val);
        update((v << 1) + 1, tm + 1, tr, id, val);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return -1;
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

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> prev(n);
    map<int, int> mp;
    map<int, int> freq;

    for(int i=0;i<n;i++) {
        if(mp.find(v[i]) != mp.end()) {
            prev[i] = mp[v[i]];
        }
        else {
            prev[i] = -1;
        }
        mp[v[i]] = i;
    }

    SegTree sg(n);
    int upto = -1;
    vector<array<int, 4>> ans;
    // i -> 4th element of that 4k + (bi, bi+1, bi+2, bi+3)
    // i -> bi+3
    // ........ j .....   i
    // upto + 1 to j-1  k  saare elements m se koi ek ka next pos j to i k bich m hona chayiye
    for(int i=0;i<n;i++) {
        freq[v[i]]++;
        int j = prev[i];
        if(j == -1 || j <= upto) continue;
        sg.update(j, i);
        // handled separately bcz segment tree can't handle this case
        // bcz we are assumig that bi != bi+1
        // example 4 32132 4 331 4 3123 4
        // thats why if bi == bi+1 means all are equal simply check using frequency
        if(freq[v[i]] >= 4) {
            upto = i;
            ans.push_back({v[i], v[i], v[i], v[i]});
            freq.clear();
        }
        else {
            int maxi = sg.query(upto + 1, j - 1);
            if(maxi > j) { // maxi < i , always true bcz segment tree is accordingly dynamically updated
                ans.push_back({v[maxi], v[i], v[maxi], v[i]});
                upto = i;
                freq.clear();
            }
        }
    }

    cout << ans.size() * 4 << "\n";
    for(auto [a, b, c, d] : ans) cout << a << " " << b << " " << c << " " << d << " ";
    

    return 0;
}