#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    int m = n*(n-1)/2;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    sort(b.begin(), b.end());
    int i = 0;
    while(i < m){
        cout<<b[i]<<" ";
        n--;
        i += n;
    }
    cout<<b.back()<<"\n";

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin>>_;
    while(_-->0){
        solve();

    }
    return 0;
}