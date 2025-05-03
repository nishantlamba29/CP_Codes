#include <bits/stdc++.h>
using namespace std;

#define int long long

int check(int mid, int k) {
    int val = 1 + mid;
    int res = mid*mid;
    for(int j=2;j<=k;j++) {
        val += res;
        if(res > 1e18) return 0;
        if(res > (1e18)/mid) return 0;
        res *= mid;
    }
    return val;
}

void solve(){
    int n;
    cin>>n;
    for(int k=2;k<=62;k++){
        int l = 2, r = 1e9;
        while(l <= r){
            int mid = (l+r)>>1;
            int val = check(mid, k);
            if(val == 0 || val > n) r = mid-1;
            else if(val == n){
                cout<<"YES\n";
                return;
            }
            else l = mid+1;
        }
    }
    cout<<"NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    solve();

    return 0;
}