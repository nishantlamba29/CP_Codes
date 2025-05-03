#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> a(k);
	for(int i=0;i<k;i++) cin>>a[i];
	
	vector<int> adj[n+1];
	
	for(int i=0;i<m;i++){
	    int u, v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	
	auto bfs = [&](int node){
	    queue<pair<int,int>> q;
	    vector<int> d(n+1, INT64_MAX);
	    d[node] = 0;
	    q.push({node, 0});
	    while(q.size()){
	        auto [node, wt] = q.front();
	        q.pop();
	        for(auto &j : adj[node]){
	            if(d[j] > d[node] + 1){
	                d[j] = d[node] + 1;
	                q.push({j, d[j]});
	            }
	        }
	    }
	    return d;
	};
	
	auto dist1 = bfs(1);
	auto dist2 = bfs(n);
	
	sort(a.begin(), a.end(), [&](const int &A, const int &B){
	    return dist1[A] - dist2[A] < dist1[B] - dist2[B];
	});
	
    int ans = 0;
    int temp = dist1[a[0]]; // temp takes prefix max of all x
    // iterating over all y
    for(int i=1;i<k;i++){
        ans = max(ans, 1 + temp + dist2[a[i]]);
        temp = max(temp, dist1[a[i]]);
    }
    
    ans = min(ans, dist1[n]);
    cout<<ans<<"\n";
	

}
