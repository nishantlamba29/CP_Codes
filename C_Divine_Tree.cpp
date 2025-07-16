#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, m;
    cin >> n >> m;
    int sum = n*(n+1) / 2;
    if(m < n || m > sum) {
        cout << "-1\n";
        return;
    }

    if(n == m) {
        for(int i=0;i<n-1;i++) {
            cout << i + 1 << " " << i + 2 << "\n";
        }
        return;
    }

    int lo = 2, hi = n;
    int ans = 2;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        // x * mid + (n-x)*mid2 == m
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