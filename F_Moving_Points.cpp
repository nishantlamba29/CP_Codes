#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    vector<int> temp;
    for(int i=0;i<n;i++) {
        cin >> v[i].second;
        temp.push_back(v[i].second);
    }
    for(int i=0;i<n;i++) cin >> v[i].first;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i=0;i<n;i++) {
        v[i].second = lower_bound(temp.begin(), temp.end(), v[i].second) - temp.begin();
    }

    int sz = temp.size();

    sort(v.begin(), v.end());

    Fenwick f(sz+1), f2(sz+1); // count and sum

    int ans = 0;
    for(int i=0;i<n;i++) {
        int cnt = f.query(v[i].second + 1);
        ans += cnt * temp[v[i].second] - f2.query(v[i].second + 1);
        f.update(v[i].second + 1, 1);
        f2.update(v[i].second + 1, temp[v[i].second]);
    }

    cout << ans;

    return 0;
}