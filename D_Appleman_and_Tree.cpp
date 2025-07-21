#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> adj[N];
int color[N];
int dp_black[N]; 
// is exactly the total number of ways to attach every child subtree (take or not take) 
// if you already have one black in your current component.
int dp_white[N];
// is exactly the number of ways to attach the children when you start with zero blacks,
// and then pick up exactly one from one of the children.

int inv(int a) {
    int b = mod - 2;
    int res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void dfs(int node = 0, int p = -1) {
    int t1 = 1;
    for(auto &j : adj[node]) {
        if(j == p) continue;
        dfs(j, node);
        int sum = (dp_black[j] + dp_white[j]) % mod;
        t1 = (t1 * sum) % mod;
    }

    int t2 = 0;
    for(auto &j : adj[node]) {
        if(j != p) {
            int t3 = (t1 * inv((dp_white[j] + dp_black[j]) % mod)) % mod;
            t2 = (t2 + (dp_black[j] * t3) % mod) % mod;
        }
    }

    if(color[node]) { // black
        dp_black[node] = t1;
        dp_white[node] = 0;
    }
    else {
        dp_white[node] = t1; // you start white (0 blacks) → stay 0 blacks by t1 ways
        dp_black[node] = t2; // you start white → pick exactly one black from children in t2 ways
    }

}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    for(int i=0;i<n;i++) cin >> color[i];

    dfs();
    cout << dp_black[0] << "\n";


    return 0;
}