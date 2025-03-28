#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n), even(n+2, 0), odd(n+2, 0);
    int e_sum = 0, o_sum = 0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        (i&1) ? e_sum += v[i] : o_sum += v[i];
    }

    even[n-2] = v[n-2], odd[n-1] = v[n-1], even[n-1] = v[n-1], odd[n-2] = v[n-2];

    for(int i=n-1;i>=0;i--){
        if(i&1){
            even[i] = even[i+1] + v[i];
            odd[i] = odd[i+1];
        }
        else {
            even[i] = even[i+1];
            odd[i] = odd[i+1] + v[i];
        }
    }
    
    int ans = -1;
    for(int i=0;i<n;i++){
        if((i&1) && (o_sum + even[i+1] - odd[i] == e_sum + odd[i] - even[i])){
            ans = i+1;
            break;
        }
        else if(!(i&1) && (o_sum - odd[i] + even[i] == e_sum + odd[i+1] - even[i])){
            ans = i+1;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
