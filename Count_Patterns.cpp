#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;
int pow(int a, int b, int k=mod){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}

int fun(int n){
    if(n == 1) return 24;
    int t1 = pow(24,n);
    int t2 = 9*pow(8,n); t2%= mod;
    int t3 = 9*pow(2,n); t3 %= mod;
    int t4 = 18*pow(3,n); t4 %= mod;
    int ans = (t1-t2+mod)%mod;
    ans = (ans+t3)%mod;
    ans = (ans+t4)%mod;
    ans = (ans-24+mod)%mod;
    return ans;
}
int countpatterns(int n){
    if(n==1){
        return 24;
    }
    int ans = 12*pow(6,n-2);  // all 1
    // cout<<ans<<" ";
    int t2 = 126*pow(18,n-2);  // all 2
    // cout<<t2<<" ";
    int t3 = 36*pow(24,n-2); // mixed 138*43^n-2
    // cout<<t3<<" ";
    return ans+t2+t3;
}

int32_t main(){
    int n;
    cin>>n;
    // int ans = countpatterns(n);
    int ans = fun(n);
    cout<<ans<<"\n";
    return 0;
}