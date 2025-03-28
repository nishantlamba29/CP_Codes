#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int modpowr(int a, int b, int k){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}

inline void n_lamba_29(){}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%mod;
    }
    int pow = modpowr(2, n-1, mod);
    int res = (ans-pow+mod)%mod;
    cout<<(res);

}