#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fact;

inline void n_lamba_29() {  
    int n;
    cin >> n;
    int ans = 50;
    for(int mask=0;mask<(1<<14);mask++) {
        int sum = 0, cnt = 0;
        for(int j=0;j<14;j++) {
            if(mask >> j & 1LL) {
                sum += fact[j];
                cnt++;
            }
        }
        if(n >= sum) {
            ans = min(ans, cnt + __builtin_popcountll(n - sum));
        }
    }
    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a = 1;
    for(int i=1;i<15;i++) {
        a *= i;
        fact.push_back(a);
    }

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}