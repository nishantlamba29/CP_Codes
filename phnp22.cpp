#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        sum += v[i];
    }
    
    int t1 = 0, t2 = 0;
    for(int i=1;i<=n;i+=(k+1)) t1 += v[i];
    for(int i=k+1;i<=n;i+=(k+1)) t2 += v[i];

    int ans = max(sum-t1, sum-t2);
    cout<<ans<<"\n";
    

    return 0;
}