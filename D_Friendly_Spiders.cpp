#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+1;
const int inf = (int)1e9;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> spf(N+1);
    vector<vector<int>> divisors(N+1);
    iota(spf.begin(), spf.end(), 0);
    for(int i=2;i*i<=N;i++) {
        if(spf[i] == i) {
            for(int j=i*i;j<=N;j+=i) {
                spf[j] = min(spf[j], i);
            }
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j+=i) {
            divisors[j].push_back(i);
        }
    }

    
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    
    int src, dest;
    cin >> src >> dest;

    vector<vector<int>> f(N+1);

    for(int i=1;i<=n;i++) {
        for(int j = a[i]; j > 1 ; j /= spf[j]) {
            f[spf[j]].push_back(i);
        }
    }
 
    queue<int> q;
    q.push(src);

    vector<int> dist(2*N+1, inf);
    vector<int> par(2*N+1, -1);
    dist[src] = 0;
    q.push(src);

    while(q.size()) {
        int node = q.front();
        q.pop();

        if(node <= n) {
            for(auto &ch : divisors[a[node]]) {
                if(ch == 1) continue;
                int j = ch + n;
                if(dist[j] > dist[node] + 1) {
                    dist[j] = dist[node] + 1;
                    par[j] = node;
                    q.push(j);
                }
            }
        }
        else {
            for(auto &j : f[node - n]) {
                if(dist[j] > dist[node] + 1) {
                    dist[j] = dist[node] + 1;
                    par[j] = node;
                    q.push(j);
                }
            }
        }
    }

    if(dist[dest] == inf) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    int temp = dest;
    while(temp != -1) {
        path.push_back(temp);
        temp = par[temp];
    }

    reverse(path.begin(), path.end());

    cout << dist[dest] / 2 + 1 << "\n";
    for(auto &i : path) {
        if(i <= n) 
        cout << i << " ";
    }
    

    return 0;
}