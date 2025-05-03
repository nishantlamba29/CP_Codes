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
    vector<int> dp(n+1, inf);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int temp = i;
        while(temp){
            int dig = temp%10;
            temp /= 10;
            if(i-dig >= 0) dp[i] = min(dp[i], dp[i-dig]+1);
        }
    }
    cout<<dp[n];
}