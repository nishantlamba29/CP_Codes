#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> next(x+1);
    for(int i=n-1;i>=0;i--){    
        vector<int> curr(x+1);
        curr[0] = 1;
        for(int j=1;j<=x;j++){
            curr[j] += next[j];
            if(j-v[i] >= 0)
            curr[j] += curr[j-v[i]];
            curr[j] %= mod;
        }
        next = curr;
    }
    cout<<next[x];
}