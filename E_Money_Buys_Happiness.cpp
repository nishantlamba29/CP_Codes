#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
template <class T > using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define int long long
const long long mod =998244353;


int func(vector<pair<int,int>>&v,int i,int money,int x){
    if(i==v.size()){
        return 0;
    }
    
    int ntake=0+func(v,i+1,money+x,x);
    int take=0;
    if(money>=v[i].first){
        take=v[i].second+func(v,i+1,money-v[i].first+x,x);
    }
    return max(take,ntake);
}

void solve(){
    int m,x;
    cin>>m>>x;
    vector<pair<int,int>>v(m);
    int hpp = 0;
    for(int i=0;i<m;i++){
        cin>>v[i].first;
        cin>>v[i].second;
        hpp += v[i].second;
    }
    vector<vector<int>>dp(m,vector<int>(hpp+1,-1));
    
    //dp[i][value]=max money left to obtain this value upto index i 
    //transition 
    //dp[i][value]=dp[i-1][value-v[i].second]+v[i].first 
    dp[0][0]=x;
    if(v[0].first==0){
        dp[0][v[0].second]=x;
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<=hpp;j++){
            if((j-v[i].second>=0)&&(dp[i-1][j-v[i].second]>=v[i].first)){
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i].second]-v[i].first+x);
                // dp[i][j]+=x;
            }
            if(dp[i-1][j]!=-1){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+x);
            }
            // dp[i][j]+=x;
        }
    }
    int ans=0;
    for(int i=hpp;i>=0;i--){
        if(dp[m-1][i]>=0){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    
    
}



int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t=1;
    cin>>t;
    while (t--) {
        solve();  // Solve the problem
    }
    return 0;
}



