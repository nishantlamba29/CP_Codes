#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;

void dijkstra(vector<vector<int>> adj[], int src, vector<int>& dist){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(pq.size()){
        int len = pq.top()[0];
        int u = pq.top()[1];
        pq.pop();
        if(len > dist[u]) continue;
        for(auto j : adj[u]){
            int v = j[0];
            int wt = j[1];
            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    vector<vector<int>> adjB[n+1], radjB[n+1], adjP[n+1], radjP[n+1];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
            if(i!=j){
                adjB[i].push_back({j,a[i][j]});
                radjB[j].push_back({i, a[i][j]});
            }
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin>>b[i][j];
            if(i!=j){
                adjP[i].push_back({j, b[i][j]});
                radjP[j].push_back({i, b[i][j]});
            }
        }
    }

    int src, dest;
    cin>>src>>dest;
    src--, dest--;
    
    vector<int> dist1(n+1, inf), dist2(n+1, inf), dist3(n+1, inf), dist4(n+1, inf);
    dijkstra(adjB, src, dist1);
    dijkstra(radjB, dest, dist2);
    dijkstra(adjP, src, dist3);
    dijkstra(radjP, dest, dist4);

    int ans = inf;
    for(int i=0;i<n;i++){
        ans = min(ans, dist1[i] + dist4[i]);
        ans = min(ans, dist2[i] + dist3[i]);
    }
    cout<<ans<<"\n";


    return 0;
}