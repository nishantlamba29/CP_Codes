#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    int offset = 0;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            p += offset;
            p %= n;
            v[p] = x;
        }
        else if(type == 2) {
            int p;
            cin >> p;
            p--;
            p += offset;
            p %= n;
            cout << v[p] << "\n";
        }
        else {
            int k;
            cin >> k;
            k %= n;
            offset += k;
            offset %= n;
        }
    }


    return 0;
}