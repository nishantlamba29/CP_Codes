#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vec vector<int>
#define vvec vector<vec>
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)

bool check(vec& v, int m, int mid){
    int sum = 0;
    for(int i=0;i<v.size();i++){
        sum += max((int)0, v[i]-mid);
    }
    if(sum >= m) return 1;
    return 0;
}
inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vec v(n);
    rep(n) cin>>v[i];
    sort(all(v));
    int l = 0,r = v.back();
    int ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        
        if(check(v, m, mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout<<ans<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n_lamba_29();

    return 0;
}
