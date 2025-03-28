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
int powr(int a, int b){ int res = 1; while(b>0){ if(b&1) res *= a; a *= a; b = b>>1; } return res;}
int modpowr(int a, int b, int k){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}
int nCr(int n, int r){ if(n<r) return 0; if(r > n-r) r = n-r; int res = 1;
    for(int i=1;i<r+1;i++) {res *= (n-r+i); res /= i;} return res;}
vector<int> isPrime, spf;
void seive(int N = 1e6){ isPrime.resize(N+1,1); isPrime[0]=0; isPrime[1]=0;
    for(int i=2;i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j] = 0;}
void SPF(int N = 1e6){ spf.resize(N+1); iota(all(spf),0);
    for(int i=2;i*i<=N;i++) if(spf[i] == i) for(int j=i*i;j<=N;j+=i) spf[j] = min(spf[j],i);}

struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        int sumA = a[0] + a[1] + a[2];
        int sumB = b[0] + b[1] + b[2];
        if (sumA == sumB) {
            return a < b;
        }
        return sumA < sumB;
    }
};

bool is_in_bounding_box(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    return min(a[0], b[0]) <= c[0] && c[0] <= max(a[0], b[0]) &&
           min(a[1], b[1]) <= c[1] && c[1] <= max(a[1], b[1]) &&
           min(a[2], b[2]) <= c[2] && c[2] <= max(a[2], b[2]);
}

inline void n_lamba_29() {
    int n;
    cin >> n;
    set<vector<int>, cmp> st;
    set<vector<int>> st2;

    // Read input points and insert into sets
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        st.insert({x, y, z, i + 1});
        st2.insert({x, y, z, i + 1});
    }

    while (!st2.empty()) {
        // Take the smallest point from st2
        vector<int> v1 = *st2.begin();
        int pos1 = v1[3];
        st2.erase(st2.begin());

        vector<int> selected_pair;
        int pos2 = -1;

        // Loop through st to find a valid pair
        for (const auto& v2 : st) {
            if (v1 == v2) continue;
            bool valid = true;

            // Check if any other point lies within the bounding box
            for (const auto& v3 : st) {
                if (v3 == v1 || v3 == v2) continue;
                if (is_in_bounding_box(v1, v2, v3)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                selected_pair = v2;
                pos2 = v2[3];
                break;
            }
        }

        // Remove the valid pair from both sets
        if (pos2 != -1) {
            st.erase(v1);
            st.erase(selected_pair);
            st2.erase(selected_pair);
            cout << pos1 << " " << pos2 << "\n";
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}