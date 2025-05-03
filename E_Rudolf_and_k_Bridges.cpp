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


inline void n_lamba_29(){
    int n,m,K,d;
    cin>>n>>m>>K>>d;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j = 0;j < m; j++) cin>>a[i][j];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
    for(int i=0;i<n;i++){
        dp[i][m-1] = 1;
        multiset<int> st;
        st.insert(1);
        for(int j=m-2;j>=0;j--){
            if(j+2+d < m){
                st.erase(st.find(dp[i][j+2+d]));
            }
            int mini = st.size() ? *st.begin() : 0;
            dp[i][j] = min(dp[i][j], a[i][j] + 1 + mini);
            st.insert(dp[i][j]);
        }
    }

    vector<int> pre(n);
    for(int i=0;i<n;i++) pre[i] = dp[i][0];

    for(int i=1;i<n;i++) pre[i] += pre[i-1];

    int mini = pre[K-1];
    for(int i=1;i<n-K+1;i++){
        mini = min(mini, pre[i+K-1] - pre[i-1]);
    }
    print(mini);

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