#include "bits/stdc++.h"
using namespace std;

#define int long long


void sop(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    sort(b.begin(), b.end());

    a[n-1] = max(a[n-1], b[m-1]-a[n-1]);

    for(int i=n-2;i>=0;i--) {
        int idx = -1, lo = 0, hi = m-1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1LL;
            if(b[mid] <= a[i] + a[i+1]){
                idx = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if(idx != -1){
            if(a[i] > a[i+1]) a[i] = b[idx] - a[i];
            else a[i] = max(a[i], b[idx] - a[i]);
        }
    }

    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--) sop();
    return 0;

}