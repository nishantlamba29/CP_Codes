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

vector<int> isPrime;
void seive(int N = 1e6){ isPrime.resize(N+1,1); isPrime[0]=0; isPrime[1]=0;
    for(int i=2;i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j] = 0;}

int dp[10][80][2][2];
int solve(string &s, int ind = 0, int sum = 0, int flag = 1, int start = 1){
    if(ind == s.size()){
        return (sum > 0 && isPrime[sum]);
    }
    if(dp[ind][sum][flag][start] != -1) return dp[ind][sum][flag][start];
    int limit = flag ? s[ind] - '0' : 9;
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int flag2 = (flag && (i == limit));
        int start2 = (start && (i == 0));
        int sum2 = sum;
        if(!start2){
            int pos = (s.size() - ind) % 2;
            if(pos) sum2 -= i;
            else sum2 += i;
        }
        ans += solve(s, ind+1, sum2, flag2, start2);
    }
    return dp[ind][sum][flag][start] = ans;

}

inline void n_lamba_29(){
    int o;
    string r;
    cin>>o>>r;
    string l = to_string(o-1);
    memset(dp, -1, sizeof(dp));
    int ans = solve(r);
    memset(dp, -1, sizeof(dp));
    ans -= solve(l);
    print(ans);

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seive(100);
    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}