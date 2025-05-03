#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin >> _;
    while (_-->0) {
        int n,c;
        cin>>n>>c;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int sum = 0;
        for(int i=1;i<n;i++) sum += v[0]*v[i];
        if(c >= sum){
            cout<<1<<"\n";
        }
        else{
            sort(v.begin(), v.end());
            vector<int> pre(n,v[0]);
            for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i];
            int t2 = 0;
            for(int i=0;i<n;i++){
                int t1 = v[i]*(pre[n-1]-pre[i]) - v[i]*(pre[i]-v[i]);
                if(c >= t1){
                    t2++;
                    c -= t1;
                }
                else{
                    break;
                }
            }
            cout<<n-t2<<"\n";
        }
    }

    return 0;
}
