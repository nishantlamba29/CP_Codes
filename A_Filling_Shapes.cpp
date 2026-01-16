#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if(n % 2 != 0) {
        cout << 0 << "\n";
    }
    else {
        n /= 2;
        int ans = 1 << n;
        cout << ans << "\n";
    }


    return 0;
}