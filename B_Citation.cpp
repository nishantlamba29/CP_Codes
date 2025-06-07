#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int lo = 0, hi = 1e9;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1LL;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(v[i] >= mid) cnt++;
        }
        if(cnt >= mid) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}