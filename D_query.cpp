#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    
    int BL_SZ = sqrt(n) + 1;

    int q;
    cin >> q;
    vector<array<int, 3>> query(q);
    for(int i=0;i<q;i++) {
        cin >> query[i][0] >> query[i][1];
        query[i][0]--, query[i][1]--;
        query[i][2] = i;
    }

    sort(query.begin(), query.end(), [&](const array<int,3> &a, const array<int,3> &b) {
        int t1 = a[0] / BL_SZ, t2 = b[0] / BL_SZ;
        if(t1 != t2) return t1 < t2;
        return (t1 & 1) ? (a[1] > b[1]) : (a[1] < b[1]);
    });

    vector<int> res(q);
    vector<int> freq(1e6+1, 0);
    int cnt = 0;
    
    auto remove = [&](int x) {
        freq[x]--;
        if(freq[x] == 0) cnt--;
    };

    auto add = [&](int x) {
        freq[x]++;
        if(freq[x] == 1) cnt++;
    };

    int st = 0, end = -1;

    for(auto &[l, r, ind] : query) {
        while(end < r) {
            end++;
            add(v[end]);
        }
        while(st > l) {
            st--;
            add(v[st]);
        }
        while(end > r) {
            remove(v[end]);
            end--;
        }
        while(st < l) {
            remove(v[st]);
            st++;
        }
        res[ind] = cnt;
    }

    for(auto i : res) cout << i << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}