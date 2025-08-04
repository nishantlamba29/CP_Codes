#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;
const int BL_SZ = 3000;
int freq[5*N];
int v[N];

int ans = 0;

void add(int ele) {
    int prev = freq[ele] * freq[ele];
    freq[ele]++;
    int curr = freq[ele] * freq[ele];
    ans += ele * (curr - prev);
}
void remove(int ele) {
    int prev = freq[ele] * freq[ele];
    freq[ele]--;
    int curr = freq[ele] * freq[ele];
    ans += ele * (curr - prev);
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        freq[v[i]] = 0;
    }
    vector<array<int,3>> query;
    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        query.push_back({l, r, i});
    }
    sort(query.begin(),query.end(), [&](const array<int,3> &a, const array<int,3> &b) {
        int b1 = a[0] / BL_SZ, b2 = b[0] / BL_SZ;
        if(b1 != b2) return b1 < b2;
        if(b1 & 1) return a[1] < b[1];
        return a[1] > b[1];
    });

    int lo = 0, ri = -1;
    vector<int> res(q);
    for(auto [l, r, ind] : query) {
        while(l < lo) add(v[--lo]);
        while(ri < r) add(v[++ri]);
        while(lo < l) remove(v[lo++]);
        while(ri > r) remove(v[ri--]);
        res[ind] = ans;
    }

    for(int i=0;i<q;i++) cout << res[i] << "\n";

    return 0;
}