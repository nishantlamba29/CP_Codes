#include <bits/stdc++.h>
using namespace std;
#define int long long
int powr(int a, int b){
    if(b == 0) return 1;
    if(b&1) return a*powr(a,b/2)*powr(a,b/2);
    return powr(a,b/2)*powr(a,b/2);
}
int fun(int n){
    if(n==1) return 0;
    return fun(n/2) + 1;
}

int solve(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 3;
    }
    if(n==3){
        return 4;
    }
    if(n==4){
        return 7;
    }
    if(n==5){
        return 8;
    }
    if(n==6){
        return 10;
    }
    if(n==7){
        return 11;
    }
    int lamb=fun(n/4) + 1;
    int val1=powr(2,lamb-1);
    int ans=0;
    ans+=4*val1;
    int i= 0;
    if(lamb -2 >= 0)
    i=powr(2,lamb-2);

    int cnt=3;
    while(i!=0){
        ans+=cnt*(i);
        i/=2;
        cnt++;
    }
    ans+=cnt*(1);

    return ans;
}


inline void n_lamba_29(){
    int n;
    cin>>n;
    int ans = 0;
    int cnt = 0;
    while(n>0){
        if(n<=7){
            ans += solve(n);
            break;
        }
        ans += solve(n);
        int lamb=fun(n/4) + 1;
        n = n - 4*(powr(2,lamb-1));

    }
    cout<<ans<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin>>_; 
    while(_-->0)
    n_lamba_29();
}