#include <bits/stdc++.h>
using namespace std;
#define int long long



int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    map<int,int> mp;
    int k = 0, cnt = 0;
    for(auto &num : v) {
        mp[num] = max(mp[num], 1LL);
        mp[num] = max(mp[num], mp[num - 1] + 1);
        if(k < mp[num]) {
            cnt = num - mp[num] + 1;
        }
        k = max(k, mp[num]);
    }

    cout << k << "\n";
    for(int i=0;i<n;i++) {
        if(cnt == v[i]) {
            cout << i + 1 << " ";
            cnt++;
        }
    }

    return 0;
}
