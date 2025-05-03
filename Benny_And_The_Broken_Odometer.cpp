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
const int mod = 998244353; // 1000000007
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }

int solve(string &s){
    vector<vvec> dp(10, vvec(2, vec(2, 0)));
    int n = s.size();
    dp[n][1][0] = 0, dp[n][0][0] = 0;
    dp[n][1][1] = 1, dp[n][0][1] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j>=0;j--){
            for(int k=0;k<2;k++){
                int limit = (k ? s[i]-'0' : 9);
                for(int l=0;l<=limit;l++){
                    dp[i][k][j] += dp[i+1][k&(l == s[i]-'0')][(j|(l==3))];
                }
            }
        }
    }
    return dp[0][1][0];
}

inline void n_lamba_29(){
    int n;
    cin>>n;
    string s = to_string(n);
    int t1 = solve(s);
    print(n-t1);
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