#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l, r;
    cin >> l >> r;
    int pos = -1;
    for(int i=63;i>=0;i--) {
        if(!(l >> i & 1) && (r >> i & 1)) {
            pos = i;
            break;
        }
    }

    for(int i=0;i<pos;i++) {
        l |= (1LL << i);
        if(r >> i & 1) r ^= (1LL << i);
    }
    cout << (l ^ r) << "\n";

    return 0;
}