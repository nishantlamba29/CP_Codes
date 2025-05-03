#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int> t;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(v[i] == 1) cnt++;
        else{
            if(cnt > 0){
                t.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt > 0) t.push_back(cnt);
    
    int sum1 = 0;
    for(auto &i : t){
        sum1 += ((i+1)*i)/2;
    }
    int maxi = t.size() == 0 ? 0 : *max_element(t.begin(), t.end());

    int sum2 = (maxi+1)*(maxi+1)/4;
    int res = n*(n+1)/2 - sum1 + sum2;
    cout<<res;
    
    

}