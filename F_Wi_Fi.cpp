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


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<vector<int>> dp(n+1, vector<int>(2, inf));
    dp[n][0] = 0, dp[n][1] = 0;
    multiset<int> st1, st2;
    st1.insert(0);
    st1.insert(0);
    for(int i=n-1;i>=0;i--){

        if(i + k + 2 <= n){
            st1.erase(st1.find(dp[i+k+2][0]));
            st1.erase(st1.find(dp[i+k+2][1]));
        }

        if(i + k + 1 < n && s[i+k+1] == '1'){
            st2.erase(st2.find(dp[i+k+1][1]));
        }
        
        dp[i][0] = min(dp[i][0], i + 1 + min(dp[i+1][1], dp[i+1][0]));

        if(s[i] == '1'){
            dp[i][1] = i + 1 + *st1.begin();
        }

        if(st2.size())
        dp[i][0] = min(dp[i][0], *st2.begin());

        st1.insert(dp[i][0]);
        st1.insert(dp[i][1]);
        if(s[i] == '1') st2.insert(dp[i][1]);
        
    }
    print(min(dp[0][1], dp[0][0]));


}