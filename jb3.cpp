#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    ll K;
    cin >> M >> N >> K;
    vector<vector<int>> a(M, vector<int>(N));
    for(auto &row : a) for(auto &x : row) cin >> x;
    if(K ==0){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++) cout << "0" << (j<N-1?" ":"\n");
        }
        return 0;
    }
    struct Edge{
        int u, v, c;
    };
    vector<Edge> edges;
    edges.reserve(2LL*M*N);
    auto get_id = [&](int i, int j) -> int {
        return i*N + j;
    };
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(i >0){
                int u = get_id(i,j);
                int v = get_id(i-1,j);
                int c = abs(a[i][j] - a[i-1][j]);
                edges.push_back(Edge{u, v, c});
            }
            if(j >0){
                int u = get_id(i,j);
                int v = get_id(i,j-1);
                int c = abs(a[i][j] - a[i][j-1]);
                edges.push_back(Edge{u, v, c});
            }
        }
    }
    sort(edges.begin(), edges.end(), [&](const Edge &x, const Edge &y) -> bool{
        return x.c < y.c;
    });
    int total = M*N;
    vector<int> parent(total);
    vector<int> sz(total, 1);
    for(int i=0;i<total;i++) parent[i]=i;
    vector<vector<int>> pending(total, vector<int>());
    for(int i=0;i<total;i++) pending[i].push_back(i);
    vector<int> answer(total, -1);
    for(auto &e : edges){
        int u = e.u;
        int v = e.v;
        auto find_set = [&](auto &find_set_ref, int x) -> int{
            return parent[x] == x ? x : parent[x] = find_set_ref(find_set_ref, parent[x]);
        };
        int ru = find_set(find_set, u);
        int rv = find_set(find_set, v);
        if(ru != rv){
            if(sz[ru] < sz[rv]){
                swap(ru, rv);
            }
            parent[rv] = ru;
            sz[ru] += sz[rv];
            for(auto &cell : pending[rv]){
                pending[ru].push_back(cell);
            }
            pending[rv].clear();
            if(sz[ru] >= K+1){
                for(auto &cell : pending[ru]){
                    if(answer[cell] == -1){
                        answer[cell] = e.c;
                    }
                }
                pending[ru].clear();
            }
        }
    }
    for(int i=0;i<total;i++){
        if(answer[i] == -1){
            answer[i] = 0;
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++) cout << answer[get_id(i,j)] << (j<N-1?" ":"\n");
    }
}