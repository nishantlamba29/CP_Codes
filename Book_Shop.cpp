#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n,x;
    cin>>n>>x;
    vector<int> price(n), pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
 
    vector<int> prev(x+1, 0), curr(x+1, 0);
 
    for(int i=1;i<=n;i++){ // yha pe = nhi tha pehle
        for(int j=x;j>=0;j--){
            curr[j] = prev[j];
            if(j+price[i-1] <= x)
            curr[j] = max(curr[j], pages[i-1] + prev[j+price[i-1]]);
        }
        prev = curr;
    }
    cout<<prev[0];
}