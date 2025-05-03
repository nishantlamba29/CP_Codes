#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> ans = {v[0]};
    for(int i=1;i<n;i++){
        int ind = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
        if(ind == ans.size()) ans.push_back(v[i]);
        else ans[ind] = v[i];
    }
    cout<<ans.size();

}