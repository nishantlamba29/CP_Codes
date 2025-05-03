#include "bits/stdc++.h"
using namespace std;

#define int long long


void sop(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1), b(m);
    a[n] = 2e9;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    for(int i=n-1;i>=0;i--){
        if(a[i] > a[i+1]){
            a[i] = b[0] - a[i];
        }
        else if(b[0] - a[i] > a[i] && b[0] - a[i] <= a[i+1]){
            a[i] = b[0] - a[i];
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