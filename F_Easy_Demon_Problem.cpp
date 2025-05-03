#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(n) for(int i=0;i<n;i++)

struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(int x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline void n_lamba_29(){
    int n,m,q, x;
    cin>>n>>m>>q;
    vector<int> a(n), b(m);
    unordered_map<int,int,CustomHash> mp1, mp2;
    int s1 = 0, s2 = 0;
    rep(n){
        cin>>a[i];
        s1 += a[i];
    }
    rep(m){
        cin>>b[i];
        s2 += b[i];
    }
    rep(n) mp1[s1-a[i]]++;
    rep(m) mp2[s2-b[i]]++;
    // x = (s1 - a)*(s2 - b)
    rep(q){
        cin>>x;
        bool f = 0;
        for(int i=1;i*i <= abs(x); i++){
            if(x % i == 0){
                if((mp1[i] && mp2[x/i]) || (mp1[x/i] && mp2[i]) || (mp1[-i] && mp2[-(x/i)]) || (mp1[-(x/i)] && mp2[-i])){
                    f = 1;
                    break;
                }
            }
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n_lamba_29();
}