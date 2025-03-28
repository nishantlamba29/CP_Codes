#include<bits/stdc++.h>
using namespace std;
main(){
    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n), maxi(n), mini(n), ans(n);
        for(i=0;i<n;i++){
            cin>>v[i];
            i == 0 ? maxi[i] = v[i] : maxi[i] = max(maxi[i-1], v[i]);
        }
        mini[n-1] = v[n-1];
        for(i=n-2;i>=0;i--) mini[i] = min(mini[i+1], v[i]);
        ans[n-1] = maxi[n-1];
        for(i=n-2;i>=0;i--) maxi[i] > mini[i+1] ? ans[i] = ans[i+1] : ans[i] = maxi[i];
        for(auto &i : ans) cout<<i<<" ";
        cout<<"\n";
    }
}
// People don't quit because its hard but beacuase its boring , Master the boredom 
// and you will master the game