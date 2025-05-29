#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, q;
    cin >> n >> q;

    int BL_SZ = max(1LL, (int)sqrt(n));

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<array<int,3>> query(q);
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

    vector<int> freq(2e5+1, 0);
    int cnt = 0;
    auto add = [&](int x) {
        if(freq[x] + 1 >= 3) {
            cnt += ((freq[x] - 1) * (freq[x]) / 2);
        }
        freq[x]++;
    };

    auto remove = [&](int x) {
        if(freq[x] >= 3) {
            cnt -= ((freq[x] - 1) * (freq[x] - 2) / 2);
        }
        freq[x]--;
    };

    int st = 0, end = -1;
    vector<int> res(q);

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

    for(int i=0;i<q;i++) {
        cout << res[i] << "\n";
    }

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    n_lamba_29();

    return 0;
}