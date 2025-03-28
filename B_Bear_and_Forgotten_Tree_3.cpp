#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
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
#define gcd __gcd
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 0x3f3f3f3f3f3f3f3fLL;
const int ninf = INT64_MIN;
const int mod = 998244353;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }

inline void n_lamba_29(){
    int n,d,h;
    cin>>n>>d>>h;
    if(d > 2*h || (n >= 3 && d == 1)){
        print(-1);
        return;
    }
    set<vec> edges;
    for(int i=1;i<=h;i++){
        edges.insert({i, i+1});
    }
    int val1 = 1, val2 = h+2;
    for(int i=0;i<(d-h);i++){
        edges.insert({val1, val2});
        val1 = val2;
        val2++;
    }
    for(int i=val2;i<=n;i++){
        edges.insert({h, i});
    }
    while(edges.size()){
        auto it = edges.begin();
        cout<<(*it)[0]<<" "<<(*it)[1]<<"\n";
        edges.erase(it);
    }

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}