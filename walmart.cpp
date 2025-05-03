#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    if(a[0]>=0){
        ans++;
        a[0]=-1;
    }
    if(a[n-1]<=0){
        ans++;
        a[n-1]=1;
    }
    int ans1=0,f1=0,ans2=0,f2=0;
    for(int i=0;i<n;i++){
        if(f1==0){
            if(a[i]>=0) f1=1;
        }
        else{
            if(a[i]<=0) ans1++;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(f2==0){
            if(a[i]<=0) f2=1;
        }
        else{
            if(a[i]>=0) ans2++;
        }
    }
    ans+=min(ans1,ans2);
    cout<<ans1<<" "<<ans2<<"\n";
    cout<<ans;
}