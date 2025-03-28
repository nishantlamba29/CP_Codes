#include <bits/stdc++.h>
using namespace std;

#define int long long

inline void n_lamba_29(){
    int k;
    cin>>k;

    double res = (double)k + sqrtl(k) + 0.5;
    int ans = res;

    // int l = 0, r = INT64_MAX;
    // int ans = -1;
    // while(l <= r){
    //     int mid = (l+r)/2;
    //     int root = sqrtl(mid);
    //     if(mid - root < k) l = mid+1;
    //     else {
    //         ans = mid;
    //         r = mid-1;
    //     }
    // }
    cout<<ans<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}