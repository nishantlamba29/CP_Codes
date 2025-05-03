#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>&a,ll n,ll k)
{
    ll sum=0;
    for(ll i=0;i<n;i++) sum+=a[i];
    a.insert(a.begin(),0);
    vector<ll>dp(n+1);
    deque<ll>dq;
    for(ll i=1;i<=k;i++)
    {
        while(!dq.empty() and dp[i-1]+a[i]<=dp[dq.back()-1]+a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(ll i=k+1;i<=n;i++)
    {
        while(!dq.empty() and dp[i-1]+a[i]<=dp[dq.back()-1]+a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        dp[i]=dp[dq.front()-1]+a[dq.front()];
        if(dq.front()==i-k) dq.pop_front();
    }
    return sum-dp[n];
}
signed main()
{
    ll n,k; cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n,k);

    return 0;
}