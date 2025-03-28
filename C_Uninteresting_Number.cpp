#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int a,int b){
    return (a==7&&b>=1)||(a==5&&b>=2)||(a==3&&b>=3)||(a==1&&b>=4)||(a==8&&b>=5)||(a==6&&b>=6)||(a==4&&b>=7)||(a==2&&b>=8);
}

inline void n_lamba_29(){
    string s;
    cin>>s;
    int sum = 0;
    vector<int> f(2,0);
    for(int i=0;i<s.size();i++){
        int dig = s[i] - '0';
        if(dig == 2) f[0]++;
        else if(dig == 3) f[1]++; 
        sum += s[i]-'0';
    }
    int rem = sum % 9;
    if(rem == 0 || f[0] >= 9){
        cout<<"YES\n";
        return;
    }
    if(check(rem, f[0]) || (rem == 3 && f[1] >= 1) || (rem == 6 && f[1] >= 2)) {
        cout<<"YES\n";
        return;
    }
    if(f[1]>=1){
        sum += 6;
        rem = sum%9;
        if(rem == 0 || check(rem, f[0])) {
            cout<<"YES\n";
            return;
        }
        if(f[1] >= 2){
            sum += 6;
            rem = sum%9;
            if(rem == 0 || check(rem, f[0])) {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}