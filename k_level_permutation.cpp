#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(int n, int k){
    vector<int> ans(n);
    int l = 1, r = n;
    for(int i=0;i<k;i++){
        for(int j=i;j<n;j+=k){
            if(i&1) ans[j] = r--;
            else ans[j] = l++;
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

void solve2(int n, int k){
    vector<int> ans(n+1, 0);
    int val = 1;
    for(int i=1;i<=k;i++){
        int tmp = n/k + ((n%k) >= i);
        int curr, sign;
        if(i&1){
            curr = val;
            sign = 1;
            val += tmp;
        }
        else{
            curr = val+tmp-1;
            sign = -1;
            val = curr + 1;
        }
        for(int j=i;j<=n;j+=k){
            ans[j] = curr;
            curr += sign;
        }
    }
    
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        solve(n,k);
        // solve2(n,k);
    }

    return 0;
}
// Nishant ...