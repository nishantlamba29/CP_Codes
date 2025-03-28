#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int> left, right;

    int N = n/2;
    int M = n - N;
    for(int i=0;i<(1<<N);i++){
        int sum = 0;
        for(int j=0;j<n/2;j++){
            if((1<<j)&i){
                sum += v[j];
            }
        }
        left.push_back(sum);
    }
    
    for(int i=0;i<(1<<M);i++){
        int sum = 0;
        for(int j=0;j<M;j++){
            if((1<<j)&i){
                sum += v[N+j];
            }
        }
        right.push_back(sum);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int ans = 0;
    for(auto i : left){
        ans += upper_bound(right.begin(), right.end(), k-i) - lower_bound(right.begin(), right.end(), k-i);
    }

    cout<<ans<<'\n';


    return 0;

}