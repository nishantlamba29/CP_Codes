#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int cnt = 0, st = -1;
    for(int i : v){
        mp[i] = max(mp[i], 1);
        mp[i] = max(mp[i], mp[i-1] + 1);
        if(mp[i] > cnt){
            cnt = mp[i];
            st = i - mp[i] + 1;
        }
    }
    cout<<cnt<<"\n";
    for(int i=0;i<n;i++){
        if(st == v[i]){
            cout<<i+1<<" ";
            st++;
        }
    }

    return 0;
}
// Nishant ...