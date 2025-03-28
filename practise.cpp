#include<bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
    public:
    vector<int> size, parent;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find_par(int x){
        if(x == parent[x]) return x;
        return parent[x] = find_par(parent[x]);
    }
    bool union_set(int u, int v){
        int p1 = find_par(u);
        int p2 = find_par(v);
        if(p1 == p2) return 0;
        if(size[p1] < size[p2]){
            swap(p1, p2);
        }
        parent[p2] = p1;
        size[p1] += size[p2];
        return 1;
    }
};

int fun1(vector<vector<int>>& mat, int n, int m){
    int N = n*m;
    DSU ds(N);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                if(j+1 < m && mat[i][j+1] == 1){
                    ds.union_set(i*m+j, i*m+j+1);
                }
            }
        }
    }
    set<int> st;
    for(int i=0;i<N;i++){
        if(mat[i/m][i%m] == 1) st.insert(ds.find_par(i));
    }
    return st.size();
}

int fun2(vector<vector<int>>& mat, int n, int m){
    int N = n*m;
    DSU ds(N);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                if(i+1 < n && mat[i+1][j] == 1){
                    ds.union_set(i*m+j, (i+1)*m+j);
                }
            }
        }
    }
    set<int> st;
    for(int i=0;i<N;i++){
        if(mat[i/m][i%m] == 1) st.insert(ds.find_par(i));
    }
    return st.size();
}

bool check(int nx, int ny, int n, int m){
    return (nx>=0 && ny>=0 && nx<n && ny<m);
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int fun3(vector<vector<int>>& mat, int n, int m){
    int N = n*m;
    DSU ds(N);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(check(nx, ny, n, m) && mat[nx][ny] == 1){
                        ds.union_set(i*m+j, nx*m+ny);
                    }
                }
            }
        }
    }
    set<int> st;
    for(int i=0;i<N;i++){
        if(mat[i/m][i%m] == 1) st.insert(ds.find_par(i));
    }
    return st.size();
}

int ddx[] = {1,1,-1,-1};
int ddy[] = {1,-1,1,-1};

int fun4(vector<vector<int>>& mat, int n, int m){
    int N = n*m;
    DSU ds(N);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                for(int k=0;k<4;k++){
                    int nx = i + ddx[k];
                    int ny = j + ddy[k];
                    if(check(nx, ny, n, m) && mat[nx][ny] == 1){
                        ds.union_set(i*m+j, nx*m+ny);
                    }
                }
            }
        }
    }
    set<int> st;
    for(int i=0;i<N;i++){
        if(mat[i/m][i%m] == 1) st.insert(ds.find_par(i));
    }
    return st.size();
}

int dcx[] = {1,1,-1,-1,0,0,1,-1};
int dcy[] = {1,-1,1,-1,1,-1,0,0};

int fun5(vector<vector<int>>& mat, int n, int m){
    int N = n*m;
    DSU ds(N);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                for(int k=0;k<8;k++){
                    int nx = i + dcx[k];
                    int ny = j + dcy[k];
                    if(check(nx, ny, n, m) && mat[nx][ny] == 1){
                        ds.union_set(i*m+j, nx*m+ny);
                    }
                }
            }
        }
    }
    set<int> st;
    for(int i=0;i<N;i++){
        if(mat[i/m][i%m] == 1) st.insert(ds.find_par(i));
    }
    return st.size();
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>mat[i][j];
    }

    int horizontal = fun1(mat, n ,m);
    int vertical = fun2(mat, n, m);
    int horizontal_vertical = fun3(mat, n, m);
    int diagonal = fun4(mat, n, m);
    int horizontal_vertical_diagonal = fun5(mat, n, m);

    cout<<horizontal<<"\n";
    cout<<vertical<<"\n";
    cout<<diagonal<<"\n";
    cout<<horizontal_vertical<<"\n";
    cout<<horizontal_vertical_diagonal<<"\n";

    return 0;
}
