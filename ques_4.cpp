#include <bits/stdc++.h>
using namespace std;
#define int long long

void rec(int i, int l, int r, int m, vector<int> &v){
    if(l == r){ // when only 1 element left to be placed
        v[r] = i;
        return;
    }
    int range = r-l-1;
    if(range < 60 && m > ((int)1<<range)){
        // when the remaining permuation can't fit in k then placing at end
        // remainig perm = (1<<range) 
        v[r] = i;
        rec(i+1, l, r-1, m-((int)1<<range), v);
    }
    else{
        // place in start
        v[l] = i;
        rec(i+1, l+1, r, m, v);
    }
}
inline void solve(){
    int n,m;
    cin>>n>>m;
    if(n <= 60 && m > ((int)1<<(n-1))){
        cout<<"-1\n";
        return;
    }
    vector<int> v(n);
    rec(1, 0, n-1, m, v);
    for(auto &i : v) cout<<i<<" ";
    cout<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    for(int __=1;__<=_;__++)
    solve();

    return 0;
}