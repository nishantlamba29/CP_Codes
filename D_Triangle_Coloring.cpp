#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int modpowr(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1LL) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    } 
    return res;
}
inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int fact = 1, fact2 = 1;
    for(int i=2;i<=n/3;i++) {
        fact = (fact * i) % mod;
    }
    for(int i=2;i<=n/6;i++) {
        fact2 = (fact2 * i) % mod;
    }
    
    int inv = modpowr(fact2, mod-2);
    fact = (fact * inv) % mod;
    fact = (fact * inv) % mod;
    
    for(int i=0;i<n;i+=3) {
        vector<int> temp = {v[i], v[i+1], v[i+2]};
        sort(temp.begin(), temp.end());
        if(temp[0] == temp[2]) {
            fact = (fact * 3) % mod; 
        }
        else if(temp[0] == temp[1]) {
            fact = (fact * 2) % mod;
        }
    }

    cout << fact << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _ = 1;
    // cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}