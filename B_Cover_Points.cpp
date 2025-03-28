#include "bits/stdc++.h"
using namespace std;
#define int long long
bool check(vector<vector<int>> v, int mid){
    for(auto &i : v) if(i[0] + i[1] > mid) return 0;
    return 1;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1];
    int l = 1, r = 1e10, ans;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(v, mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid + 1;
    }
    cout<<ans;
}