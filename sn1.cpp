#include <bits/stdc++.h>
using namespace std;
int dfs(int i, vector<vector<int>> &adj, vector<int> &ans, int &cnt) {
    int sum = 0;
    int szz = 0;
    int maxi = 0;
    int maxi2 = 0;
    int maxa = 0;
    for (auto j : adj[i]){
       int sz= dfs(j, adj,ans,cnt );
       szz += sz;
       sum += sz;

       if(maxi<=sz){
        if(maxi==sz)maxi2 = max(ans[j], maxi2);
           else
               maxi2 = ans[j];
           maxi = sz;
           
       }
       maxa = max(ans[j], maxa);
    }
    sum -= maxi;
    int rem=0;
    if (sum >= maxi){
        // ans[i] = (sum + maxi) / 2;
        ans[i] = maxi;
    }
    else{
        ans[i] = (sum);
        rem = maxi - sum;
    }
    
    ans[i] = ans[i] + min(maxi2, rem / 2);
    ans[i] = max(ans[i], maxa);
    cnt = max(cnt, ans[i]);
    return szz + 1;
}

int maximumpossiblesquads(vector<int> &arr){
    int n= arr.size();
    vector<vector<int>> adj(n + 1);
    vector<int> vec;
    for (int i = 1; i < n + 1;  i++)
    {
        vec.push_back(arr[i-1]);
        adj[arr[i-1]].push_back(i);
    }
    vector<int> ans(n + 1);
    int cnt = 0;
    dfs(0, adj,ans, cnt);
    return cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int ans = maximumpossiblesquads(v);
    cout<<ans;
}