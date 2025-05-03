#include <bits/stdc++.h>
using namespace std;

#define int long long

int get(int n){
    return (n*(n+1))/2;
}

int check(int mid, int k){
    if(mid <= k){
        return get(mid);
    }
    int ans = get(k);
    int term = mid-k;
    ans += get(k-1) - get(k-1-term);
    return ans;
}
inline void n_lamba_29(){
    int k,x;
    cin>>k>>x;
    
    int l = 1, r = 2*k, res = 2*k-1;
    while(l <= r) {
        int mid = (l+r)>>1;
        int curr = check(mid, k);
        if(curr >= x){
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout<<res<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}