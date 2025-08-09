#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, k1, k2;
const int N = 2e5 + 5;
vector<int> adj[N];
int ans = 0;
 
void merge(vector<int> &my, vector<int> &ch) {
    if((int)my.size() < (int)ch.size()) swap(my, ch);
 
    for(int i=(int)ch.size()-1;i>=0;i--) {
        int d = (int)ch.size() - i - 1;
        if(d > k2) break;
        int t1 = ch[i] - (i > 0 ? ch[i-1] : 0); // count of nodes in child subtree at depth d
 
        // get the count of node from other subtree having depth
        // in range k1 - d to  k2 - d
        if(k1 - d > (int)my.size() - 1) continue;
        int i1 = min((int)my.size() - 1, (int)my.size() - (k1 - d) - 1);
        int i2 = (int)my.size() - (k2 - d + 1) - 1;
        int t2 = 0;
        t2 = my[i1] - (i2 >= 0 ? my[i2] : 0); 
 
        ans += t1 * t2;

    }
 
    int hi = (int)my.size() - 1;
    for(int i=(int)ch.size()-1;i>=0;i--) {
        my[hi] += ch[i];
        hi--;
    }
    ch.clear();
}
 
vector<int> dfs(int node = 1, int p = -1, int d = 0) {
    vector<int> my(1, 1);
    // suff[i] denote count of node at depth >= i in subtree of node
    for(auto j : adj[node]) if(j != p) {
        vector<int> ch = dfs(j, node, d + 1);
        ch.push_back(ch.back());
        merge(my, ch);
    }
    return my;
}
 
int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k1 >> k2;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs();
    cout << ans << "\n";
 
    return 0;
}