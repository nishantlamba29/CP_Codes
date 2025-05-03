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

inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    int mm = m;
    int f1 = 0, f2 = 0;
    int temp = n;
    while(temp % 2 == 0){
        f1++;
        temp /= 2;
    }
    while(temp % 5 == 0){
        f2++;
        temp /= 5;
    }
    if(f1 == f2){
        int num = 1;
        while(m >= 10){
            num *= 10;
            m /= 10;
        }
        print(n*num*m);
    }
    else if(f1 > f2){
        int diff = f1-f2;
        int num = 1;
        for(int i=0;i<diff;i++){
            if(num*5 <= mm){
                num *= 5;
                m /= 5;
            }
        }
        while(m >= 10){
            num *= 10;
            m /= 10;
        }
        print(num*n*m);
    }
    else{
        int diff = f2-f1;
        int num = 1;
        for(int i=0;i<diff;i++){
            if(num*2 <= mm){
                num *= 2;
                m /= 2;
            }
        }
        while(m >= 10){
            num *= 10;
            m /= 10;
        }
        print(num*n*m);
    }

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