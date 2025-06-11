#include <bits/stdc++.h>
using namespace std;
#define int long long
using i128 = __int128_t;
const int inf = 2e18;

class line {
public:
    int m, c;
    line(int m, int c) : m(m), c(c) {}
};

class CHT_Max {
public:
    vector<line> hull;
    CHT_Max() {
        hull.clear();
    }
    bool bad(line l1, line l2, line l3) {
        i128 a = (i128)(l2.c - l1.c) * (l2.m - l3.m);
        i128 b = (i128)(l3.c - l2.c) * (l1.m - l2.m);
        return a <= b;
    }
    int val(int ind, int x) {
        return hull[ind].m * x + hull[ind].c;
    }
    void add(line l) {
        hull.push_back(l);
        int sz = hull.size();
        while(sz >= 3 && bad(hull[sz-3], hull[sz-2], hull[sz-1])) {
            hull.erase(hull.end() - 2);
            sz--;
        }
    }
    int query(int x) {
        if(hull.empty()) return -inf;
        int lo = 0, hi = hull.size() - 1, maxAns = -inf;
        while(lo <= hi) {
            int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
            int val1 = val(mid1, x) , val2 = val(mid2, x);
            maxAns = max({maxAns, val1, val2});
            if(val1 <= val2) lo = mid1 + 1;
            else hi = mid2 - 1;
        }
        return maxAns;
    }
};

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);


    int n;
    cin >> n;
    vector<array<int,3>> v(n);
    for(auto &a : v) cin >> a[0] >> a[1] >> a[2];

    sort(v.begin(), v.end());

    CHT_Max ch;
    ch.add(line(0, 0));

    int ans = 0;
    for(auto &[x, y, a] : v) {
        // y = mx + c
        // dp[i] = xi * yi - ai + max( dp[j] - xj * yi ) = xi * yi - ai + max( -xj * yi + dp[j] )
        int dp = x * y - a + ch.query(y);
        ch.add(line(-x, dp));
        ans = max(ans, dp);
    }
    cout << ans << "\n";
 
    return 0;
}