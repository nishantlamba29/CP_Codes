#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int lo = 1, hi = 1000, ans = 2;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            cout<<"? 1 "<<mid<<endl;
            int area;
            cin>>area;
            if(area > mid){
                hi = mid - 1;
            }
            else{
                ans = mid;
                lo = mid + 1;
            }
        }
        cout<<"! "<<ans+1<<endl;
    }
    return 0;
}