#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int q1 = 0;
    for(int i=0;i<30;i++) {
        if(i % 2 == 0) {
            q1 |= (1 << i);
        }
    }
    int q2 = q1 << 1;

    // int q1 = 357913941; // 010101....1
    // int q2 = 715827882; // 101010....0

    int t;
    cin >> t;
    while(t--) {
        cout << q1 << endl;
        int ans1;
        cin >> ans1;
        cout << q2 << endl;
        int ans2;
        cin >> ans2;
        ans1++;
        ans2++;
        
        int one = (~ans1) & q2;
        int both = ans1 & q2 & (ans1 >> 1);

        one |= (~ans2) & q1;
        both |= ans2 & q1 & (ans2 >> 1);

        int x = both;
        int y = (one | both);

        cout << "!" << endl;
        int m;
        cin >> m;

        int ans = (m | x) + (m | y);
        cout << ans << endl;

    }
    

    return 0;
}