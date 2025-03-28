#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n == 1){
        cout<<v[0]<<"\n";
        return 0;
    }
    int sum = 0;
    sort(v.begin(), v.end());
    int k = 2;
    for(int i=0;i<n-1;i++){
        sum += k*v[i];
        k++;
    }
    sum += (k-1)*v[n-1];
    cout<<sum<<"\n";

    return 0;
}