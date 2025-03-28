#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n + 1, 1);
    }
    int find_par(int x){
        if (x == parent[x])
            return x;
        return parent[x] = find_par(parent[x]);
    }
    bool union_set(int u, int v){
        int p1 = find_par(u), p2 = find_par(v);
        if (p1 == p2)
            return 0;
        if (size[p1] < size[p2]){
            parent[p1] = p2;
            size[p2] += size[p1];
        }
        else{
            parent[p2] = p1;
            size[p1] += size[p2];
            return 1;
        }
    }
};

inline void n_lamba_29(){
    vector<int> v = {1, 1, 1, 1, 1, 1, 1};
    DSU ds(100);
    int i = 0, j = v.size() - 1;
    int ans = 0;
    while (i < j)
    {
        if (ds.union_set(v[i], v[j]))
            ans++;
        i++;
        j--;
    }
    cout << ans << "\n";
}

int32_t main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    n_lamba_29();

    return 0;
}