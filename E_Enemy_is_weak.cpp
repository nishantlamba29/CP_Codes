#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    int n;
    vector<int> bit;
public:
    Fenwick(int n) {
        this->n = n;
        bit = vector<int>(n+1, 0);
    }

    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }

    int query(int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= id & -id;
        }
        return ans;
    }
};


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(), v.end());
    vector<int> pre(n), suff(n);
    
    Fenwick f(n);
    for(int i=0;i<n;i++) {
        pre[i] = i - f.query(v[i].second - 1);
        f.update(v[i].second, 1);
    }
    Fenwick f2(n);
    for(int i=n-1;i>=0;i--) {
        suff[i] = f2.query(v[i].second - 1);
        f2.update(v[i].second, 1);
    }
    long long ans = 0;

    for(int i=0;i<n;i++) {
        ans += (long long)pre[i] * suff[i];
    }
    cout << ans << "\n";

    return 0;
}