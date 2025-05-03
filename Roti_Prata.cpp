#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vvec vector<vec>
#define all(v) v.begin(),v.end()
#define rep(n) for(int i=0;i<n;i++)

/*

    T = R*M*(M+1)/2;
    t-> time to cook M dishes whose rank is R
    solving quadratic equation 

    M = ( -1 + sqrtl(1+8*(T/R)) ) / 2

*/



/*

other approach

bool check(vector<int>& rank, int m, int mid){
    int c1 = 0; // cooking time
    int c2 = 0; // currently 0 dish prepared;
    for(int i=0;i<rank.size();i++){
        c1 = rank[i];
        int j = 2;
        while(c1 <= mid){
            c2++;
            c1 += rank[i]*j;
            j++;
        }
    }
    if(c2 >= m) return 1;
    return 0;
}

*/
bool check(vector<int>& v, int m, int mid){
    int c1 = 0;
    for(int i=0;i<v.size();i++){
        int r = v[i];
        int t = mid;
        int dish = ( -1 + sqrtl(1 + 8*(t/r))) / 2;
        c1 += dish;
    }
    if(c1 >= m) return 1;
    return 0;
}
inline void n_lamba_29(){
    int m,n;
    cin>>m>>n;
    vector<int> v(n);
    rep(n) cin>>v[i];
    sort(all(v));
    int l = 0, r = v[0]*(m*(m+1)/2);
    int ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(v, m, mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tending_to_;
    cin>>tending_to_;
    while(tending_to_-->0)
    n_lamba_29();

    return 0;
}
// Nishant ...