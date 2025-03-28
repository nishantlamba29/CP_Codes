#include <bits/stdc++.h>
using namespace std;
#define int long long
// const long long mod = 1e9 + 7;

int osc(int i,vector<vector<pair<int,int>>>&op){
    vector<pair<int,int>>temp;
    for(int j=0;j<op[i].size();j++){
        temp.push_back(op[i][j]);
        
    }
    sort(temp.begin(),temp.end());
    int ans=1;
    for(int j=0;j<temp.size();j++){
        if(temp[j].second==1){
            ans++;
        }
    }
    return ans;
}
int tsc(int i,int j,vector<vector<pair<int,int>>>&op){
    int l1=1;
    int l2=2;
    int len1=0;
    int len2=0;
    vector<pair<int,pair<int,int>>>temp;
    for(int k=0;k<op[i].size();k++){
        temp.push_back({op[i][k].first,{op[i][k].second,i}});
    }
    for(int k=0;k<op[j].size();k++){
        temp.push_back({op[j][k].first,{op[j][k].second,j}});
    }
    sort(temp.begin(),temp.end());
    
    for(int k=0;k<temp.size();k++){
        if(temp[k].second.second==i){
            if(temp[k].second.first==1){
                len1++;
            }
            else{
                l1++;
                len1--;
            }
        }   
        else{
            if(temp[k].second.first==1){
                len2++;
            }
            else{
                l2++;
                len2--;
            }
        }
        if(l1+len1==l2){
            l2++;
        }
    }
    int ans=(l2+len2)-(l1+len1);
    return ans;
}

int func(int last,int mask,vector<vector<int>>&dist,int n,vector<vector<int>>&dp){
    
    if((1LL<<n)-1==mask){
        return dist[last][last];
    }
    if(dp[last+1][mask]!=-1){
        return dp[last+1][mask];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(!((1LL<<i)&mask)){
            if(last!=-1){
                int val1=dist[last][i]+func(i,mask|(1LL<<i),dist,n,dp);
                ans=min(ans,val1);
            }
            else{
                int val1=0+func(i,mask|(1LL<<i),dist,n,dp);
                ans=min(ans,val1);
            }
            
            
        }
    }
    return  dp[last+1][mask]=ans;
}

void solve(){
   
   int n,q;
   cin>>n>>q;
   vector<vector<pair<int,int>>>op(n);
   
   for(int i=0;i<q;i++){
       int val;
       char x;
       cin>>val>>x;
       val--;
       if(x=='+'){
           op[val].push_back({i,1});
       }
       else{
           op[val].push_back({i,0});
       }
   }
   
   vector<vector<int>>dist(n,vector<int>(n));
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(i!=j){
               dist[i][j]=tsc(i,j,op);
           }
           else{
               dist[i][j]=osc(i,op);
           }
       }
   }
   vector<vector<int>>dp(n+1,vector<int>((1LL<<n),-1));
   int ans=func(-1,0,dist,n,dp);
   cout<<ans<<endl;
   
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t=1;
    while (t--) {
        solve();  // Solve the problem
    }
    return 0;
}