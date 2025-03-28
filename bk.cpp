#include <bits/stdc++.h>
using namespace std;

const int maxi = 3001;
vector<int> adj[maxi];
int match[maxi], dist[maxi];
bool visited[maxi];
int k, n, m;

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= k; ++u) {
        if (!match[u]) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] >= dist[0]) continue;

        for (int v : adj[u]) {
            if (dist[match[v]] == INT_MAX) {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
    }
    return dist[0] != INT_MAX;
}

bool dfs(int u) {
    if (u == 0) return true;
    for (int v : adj[u]) {
        if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    dist[u] = INT_MAX;
    return false;
}

int hopcroftKarp() {
    memset(match, 0, sizeof(match));
    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= k; ++u) {
            if (!match[u] && dfs(u)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    cin >> k;
    vector<vector<int>> v(k);
    for (int i = 1; i <= k; ++i) {
        int numChoices;
        cin >> numChoices;
        for (int j = 0; j < numChoices; ++j) {
            int fruit;
            cin >> fruit;
            v[i-1].push_back(fruit);
            adj[i].push_back(k + fruit);
        }
    }

    int totalPieces;

    cin >> n >> m;
    totalPieces = n * m;

    // idk if this is correct or not
    set<int> st;
    for(int i=1;i<=totalPieces;i++) st.insert(i);
    sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b){
        return a.size() < b.size();
    });
    int cnt = 0;
    for(int i=0;i<k;i++){
        int m = v[i].size();
        for(int j=0;j<m;j++){
            if(st.find(v[i][j]) != st.end()){
                st.erase(v[i][j]);
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<"\n";


    // int maxFriendsHappy = hopcroftKarp();
    // cout << maxFriendsHappy << endl;

    return 0;
}