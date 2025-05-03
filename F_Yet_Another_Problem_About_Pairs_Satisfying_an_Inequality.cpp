#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define R return
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
const int inf = 0x3f3f3f3f3f3f3f3fLL;
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }


inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(n) cin>>v[i];
    vector<int> temp;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(v[i] < i+1){
            temp.pb(i+1);
            int ind = upper_bound(all(temp), v[i]-1) - temp.begin();
            ans += ind;
        }
    }
    print(ans);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}