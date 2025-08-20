#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<int> l1(30);
    vector<int> p = v;
    for(int i=1;i<=n;i++) p[i] ^= p[i-1];
    // p[r] | p[l] - p[r] &p[l]
    
    int ans = 0;
    for(int r=1;r<=n;r++) {
        int sum = 0;
        for(int j=0;j<30;j++) {
            if((1LL << j) & p[r]) {
                sum = sum + (1 << j) * r;
                sum = sum - (1LL << j) * l1[j];
            }
            else {
                sum = sum + (1LL << j) * l1[j];
            }
        }
        ans += sum;
        for(int j=0;j<30;j++) {
            if((p[r] >> j & 1)) {
                l1[j]++;
            }
        }
        ans -= v[r];
    }
    cout << ans << "\n";

    return 0;
}