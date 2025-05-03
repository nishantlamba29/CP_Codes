#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int maxi = 0, a;
    int64_t sum = 0;
    for(int i=0;i<n;i++) {
        cin >> a;
        sum += a;
        maxi = max(maxi, a);
    }
    if(sum & 1LL || maxi > sum - maxi) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}