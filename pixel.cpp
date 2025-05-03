#include<bits/stdc++.h>
using namespace std;
#define int long long
int fun(vector<int> nums, int n){
    vector<int> v = nums;
    int sum = accumulate(v.begin(), v.end(), 0);
    for(int z=0;z<2;z++){
        int k = 0;
        for(int i=0;i<n;i++){
            k++;
            if(v[i] > k){
                v[i] = k;
            }
            else{
                k = v[i];
            }
        }
        reverse(v.begin(), v.end());
    }
    int t = *max_element(v.begin(), v.end());
    // this will not print the actual array after operation , it only gives number of operation
    return sum - t*t;
}
int32_t main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int ans = fun(v, n);
        cout<<ans<<"\n";
    }
    return 0;
}