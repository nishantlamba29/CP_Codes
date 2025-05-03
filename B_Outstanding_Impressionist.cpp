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
    int n;
    cin>>n;
    vector<vec> v;
    map<int,int> mp;

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v.pb({l, r});
        if(l == r){
            mp[l]++;
        }
    }
    vec t1;
    vvec t2;
    for(auto &[l, r] : mp){
        t1.pb(l);
    }
    sort(all(t1));

    for(auto i = 0; i < t1.size(); i++){
        int st = t1[i];
        while(i+1 < t1.size() && t1[i] + 1 == t1[i+1]) i++;
        t2.pb({st, t1[i]});
    }

    for(int i=0;i<n;i++){
        int l = v[i][0], r = v[i][1];
        if(l != r){
            int t3 = 0;
            for(auto &j : t2){
                if(j[0] <= l && j[1] >= r){
                    t3 = 1;
                    break;
                }
            }
            cout << (t3 ? 0 : 1);
        }
        else{
            cout<<(mp[l] > 1 ? 0 : 1);
        }
    }
    cout<<"\n";

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