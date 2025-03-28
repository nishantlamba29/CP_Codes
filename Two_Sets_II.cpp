#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int modpowr(int a, int b, int k) {
    int res = 1;
    while(b>0){
        if(b&1) res = (res*a)%k;
        a = (a*a)%k;
        b = b>>1;
    }
    return res%k;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int sum = (n*(n+1))>>1;
    if(sum&1){
        cout<<0;
        return 0;
    }
    int tar = sum >> 1;
    vector<int> prev(tar+1);
    prev[0] = 1;
    for(int i=1;i<=n;i++){
        vector<int> curr(tar+1);
        for(int j=0;j<=tar;j++){
            curr[j] = prev[j];
            if(j - i >= 0) curr[j] = (curr[j] + prev[j-i]) % mod;
        }
        prev = curr;
    }
    // ans = prev[tar]/2  --> divide by 2 due to symmtry
    // so i have to divide by modular inverse of 2 instead of 2

    int modinv2 = modpowr(2, mod-2, mod); // by fermats theorem

    int ans = (prev[tar]*modinv2) % mod;
    cout<<ans;

    // or below one
    // cout << (prev[tar] * ((mod + 1) / 2)) % mod;

}