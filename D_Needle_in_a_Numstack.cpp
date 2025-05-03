#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> a(k), b(k);
    for(int i=0;i<k;i++) {
        cout << "? " << i + 1 << endl;
        cin >> a[i];
    }
    for(int i=0;i<k;i++) {
        cout << "? " << n - i << endl;
        cin >> b[i];
    }

    int lo = k, hi = n - k - 1, ans = k - 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        int ind = -1;
        for(int j=0;j<k;j++) {
            int ii = mid - j;
            if(a[ii % k] != b[(n - ii - 1) % k]) {
                ind = ii;
                break;
            }
        }
        if(ind == -1) break;
        cout << "? " << ind + 1 << endl;
        int x;
        cin >> x;
        if(x == a[ind % k]) {
            ans = ind;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    int i = ans + 1;
    if(i < n - k && a[i % k] == b[(n - i - 1) % k]) {
        cout << "! -1" << endl;
    }
    else {
        int l1 = ans + 1, l2 = n - l1;
        cout << "! " << l1 << " " << l2 << endl;
    }

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}