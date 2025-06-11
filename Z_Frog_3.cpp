#include <bits/stdc++.h>
using namespace std;
#define int long long
using i128 = __int128_t;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

class Line {
public:
    int m, c;
    Line(int m, int c) : m(m), c(c) {}
};

class CHT_Min {
public:
    vector<Line> hull;
    CHT_Min() {
        hull.clear();
    }
    bool bad(Line& l1, Line& l2, Line& l3) {
        i128 val1 = (i128)(l2.c - l1.c) * (l2.m - l3.m);
        i128 val2 = (i128)(l3.c - l2.c) * (l1.m - l2.m);
        return val1 >= val2;
    }
    void add(Line& l1) {
        hull.push_back(l1);
        int sz = hull.size();
        while (sz >= 3 && bad(hull[sz - 3], hull[sz - 2], hull[sz - 1])) {
            hull.erase(hull.end() - 2);
            sz--;
        }
    }
    int val(int ind, int x) {
        return hull[ind].m * x + hull[ind].c;
    }
    int query(int x) {
        if (hull.empty()) return inf;
        int lo = 0, hi = hull.size() - 1, minAns = inf;
        while(lo <= hi) {
            int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
            int val1 = val(mid1, x), val2 = val(mid2, x);
            minAns = min({minAns, val1, val2});
            if (val1 <= val2) hi = mid2 - 1;
            else lo = mid1 + 1;
        }
        return minAns;
    }
};

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];

    CHT_Min ch;

    vector<int> dp(n);
    Line l(-2 * h[0], h[0] * h[0]);
    ch.add(l);
    for(int i=1;i<n;i++) {
        dp[i] = c + h[i] * h[i] + ch.query(h[i]);
        Line l(-2 * h[i], h[i] * h[i] + dp[i]);
        ch.add(l);
    }
    cout << dp[n-1];

    return 0;
}