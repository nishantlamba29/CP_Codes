#include <bits/stdc++.h>
using namespace std;
// First you make it work, then you can always make it beautiful

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(b.rbegin(), b.rend());
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            cout << b[j++] << " ";
        }
        else {
            cout << a[i++] << " ";
        }
    }
    while(i < n) cout << a[i++] << " ";
    while(j < m) cout << b[j++] << " ";
    cout << "\n"; 

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    cin >> _;
    while (_-->0) {
        solve();
    }

    return 0;
}