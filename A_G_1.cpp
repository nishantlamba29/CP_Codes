#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int cnt = 0;
    cin >> k;
    for(int i=0;i<n;i++) {
        cnt += (v[i] >= k);
    }
    cout << cnt << "\n";


    return 0;
}