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
    int maxSum = accumulate(v.begin(), v.end(), 0LL);
    // vector<vector<int>> dp(n+1, vector<int>(maxSum+1));
    vector<int> prev(maxSum+1);
    prev[0] = 1;
    for(int i=1;i<=n;i++){
        vector<int> curr(maxSum+1);
        curr[0] = 1;
        for(int j=0;j<=maxSum;j++){
            curr[j] = prev[j];
            if(j - v[i-1] >= 0) curr[j] = prev[j] || prev[j-v[i-1]];
        }
        prev = curr;
    }
    vector<int> ans;
    for(int i=1;i<=maxSum;i++) if(prev[i]) ans.push_back(i);
    cout<<ans.size()<<"\n";
    for(auto &i : ans) cout<<i<<" ";
    
}