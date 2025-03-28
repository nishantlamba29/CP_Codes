#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>>v1;
    int i=1;
    vector<int>temp;
    temp.push_back(v[0]);
    
    while(i<n){
        if(v[i]<=v[i-1]){
            // cout<<"i am in 1 "<<i<<endl;
            temp.push_back(v[i]);
            // cout<<temp.size()<<endl;
            i++;
        }
        else{
            v1.push_back(temp);
            temp.clear();
            // cout<<temp.size()<<endl;
            i++;
        }
    }
    v1.push_back(temp);
    int rnd=1;
    int mini=v1[0][v1[0].size()-1];
    int ex=INT_MIN;
    
    for(int i=1;i<v1.size();i++){
        int rnd1=0;
        for(int j=0;j<v1.size();j++){
            if(v1[i][j]>mini){
                rnd1++;
            }
            else{
                mini=v1[i][j];
            }
        }
        ex=max(ex,rnd1);
    }
    if(ex!=INT_MIN){
        rnd+=ex;
    }
    cout<<rnd<<endl;
}


int32_t main(){
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}