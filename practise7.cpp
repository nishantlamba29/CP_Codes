#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

vector<vector<int>> adj;   // adjacency list
vector<vector<int>> radj;  // reverse adjacency list
vector<int> c;             // no. of people living in towns
vector<bool> vis;          // visited array for dfs

vector<int> topo;

void dfs1(int u) {
  vis[u] = true;
  for (auto v : adj[u]) {
    if (!vis[v]) {
      dfs1(v);
    }
  }
  topo.pb(u);
}

vector<int> temp;
int id;
vector<int> code;  // index of component to which node belongs
vector<int> cnew;  // value of c_i in new graph (condensed SCC graph or DAG)

void dfs2(int u) {
  vis[u] = true;
  temp.pb(u);
  code[u] = id;
  cnew[id] += c[u];
  for (auto v : radj[u]) {
    if (!vis[v]) {
      dfs2(v);
    }
  }
}

vector<vector<int>> comp;  // SCC components

int32_t main() {

  int n, m;
  cin >> n >> m;
  adj.resize(n);
  radj.resize(n);
  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edges.pb({u, v});
    adj[u].pb(v);   // adjacency list of graph
    radj[v].pb(u);  // reverse graph
  }

  vis.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs1(i);
  }
  
  reverse(topo.begin(), topo.end());
  // similar to pushing and popping in stack
  // instead we can reverse the vector

  // Kosaraju's algorithm to find SCC's
  vis.assign(n, false);
  code.resize(n);
  cnew.resize(n);
  id = 0;
  for (int i = 0; i < n; i++) {
    int t = topo[i];
    if (vis[t]) continue;
    temp.clear();
    dfs2(t);
    comp.pb(temp);
    id++;
  }
//   for(auto i : comp){
//     for(auto j : i) cout<<j<<" ";
//     cout<<"\n";
//   }
  vector<int> new_topo;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int new_node = code[topo[i]];
    if (!st.count(new_node)) {
      st.insert(new_node);
      new_topo.pb(new_node);
    }
  }
  vector<vector<int>> new_adj(id);

  for (auto e : edges) {
    int u, v;
    u = code[e.first];
    v = code[e.second];
    if (u != v) {
      new_adj[u].pb(v);
    }
  }
//   for(int i=1;i<id;i++){
//     cout<<i<<" -> ";
//     for(auto j : new_adj[i]) cout<<j<<" ";
//     cout<<"\n";
//   }

  vector<int> dp(id, 0);  // Initialise dp[] with 0

  reverse(new_topo.begin(), new_topo.end());
  // Iterate through reverse topological sorting order
  // Sink first, then Source..

  for(auto i : cnew) cout<<i<<" ";cout<<"\n";
  for(auto i : code) cout<<i<<" ";cout<<'\n';
  for(auto i : new_topo) cout<<i<<" "; cout<<"\n";
  for (auto u : new_topo) {
    for (auto v : new_adj[u]) {
      dp[u] = max(dp[u], dp[v]);
    }
    dp[u] += cnew[u];
  }

  for (int i = 0; i < n; i++) {
    cout << dp[code[i]] << ' ';
  }

  return 0;
}