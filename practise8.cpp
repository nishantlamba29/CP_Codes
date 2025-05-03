#include<bits/stdc++.h>
using namespace std;

int dfs(int node, int pt, vector<int> adj[], vector<int> &pre, vector<int>& A){
    pre[node] = A[node];
    for(auto j : adj[node]){
        if(j == pt) continue;
        pre[node] = min(pre[node], dfs(j, node, adj, pre, A));
    }
    return pre[node];
}

int fun(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<int> adj[n+1];
    for(auto i : B){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> pre(n, 0);
    dfs(0, -1, adj, pre, A);
    
    int ans = accumulate(pre.begin(), pre.end(), 0) + *min_element(A.begin(), A.end());
    return ans;
}

int main(){ 
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    vector<vector<int>> B;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        B.push_back({u, v});
    }
    int res = fun(A, B);
    cout<<res<<"\n";

    return 0;
}
