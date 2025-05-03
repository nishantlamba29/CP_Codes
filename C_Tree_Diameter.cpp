#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29(){
    int n;
    cin>>n;
    int ans;
    cout<<1<<" "<<n-1<<" ";
    for(int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    cin>>ans;

    int lo = 2, hi = n, node = 2;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        cout<<1<<" "<<mid-lo+1<<" "<<1<<" ";
        for(int i=lo;i<=mid;i++) cout<<i<<" ";
        cout<<endl;
        int temp;
        cin>>temp;
        if(temp == ans){
            node = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout<<1<<" "<<n-1<<" "<<node<<" ";
    for(int i=1;i<=n;i++) if(i != node) cout<<i<<" ";
    cout<<endl;
    cin>>ans;
    cout<<-1<<" "<<ans<<endl;

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    while(n--)
    n_lamba_29();

}