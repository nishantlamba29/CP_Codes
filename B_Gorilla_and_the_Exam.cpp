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
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    vector<int> v(n);
    rep(n) {
        cin>>v[i];
        mp[v[i]]++;
    }
    // set<pii, greater<pii>> st;
    set<pii> st2;

    for(auto &[f,s] : mp){
        // st.insert({s, f});
        st2.insert({s, f});
    }
    // int maxi = (*st.begin()).first;
    while(st2.size()){
        auto it = st2.begin();
        int ele = (*it).second;
        int fr = (*it).first;
        if(k >= fr){
            k -= fr;
        }
        else break;
        st2.erase(it);
        // st.erase({fr, ele});
    }
    int ans = st2.size();
    print(max(1LL, ans));


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