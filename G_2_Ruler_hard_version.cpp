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
        int l = 1, r = 1000, ans = 2;
        while(l <= r){
            int mid1 = l + (r - l)/3;
            int mid2 = r - (r - l)/3;
            cout<<"? "<<mid1<<" "<<mid2<<endl;
            int area;
            cin>>area;
            if(area == (mid1+1)*(mid2+1)){
                ans = mid1;
                r = mid1 - 1;
            }
            else if(area == (mid2 + 1)*mid1){
                ans = mid2;
                l = mid1 + 1;
                r = mid2 - 1;
            }
            else{
                l = mid2 + 1;
            }
        }
        cout<<"! "<<ans<<endl;
    }
    return 0;
}