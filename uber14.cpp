#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int get(int x, vector<int> &par){
    return (x == par[x] ? x : get(par[x], par));
}
bool merge(int u, int v, vector<int> &par, vector<int> &sz){
    int p1 = get(u, par), p2 = get(v, par);
    if(p1 == p2) return 0; 
    if(sz[p1] < sz[p2]) swap(p1, p2);
    par[p2] = p1;
    sz[p1] += sz[p2];
    return 1;
}
int fun(vector<vector<int>> &points){
    int n = points.size();
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({i, j, dist});
        }
    }
    vector<int> par(n+1);
    iota(par.begin(), par.end(), 0);
    vector<int> sz(n+1, 1);
    int ans = 0;
    sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int>& b){
        return a[2] < b[2];
    });
    for(auto &i : edges){
        int u = i[0], v = i[1], w = i[2];
        if(merge(u,v, par,sz)){
            ans += w;
        }
    }
    return ans;
}

// void disunion(vector<int>&parent,vector<int>&size,int u,int v){
//     int par1=findup(parent,u);
//     int par2=findup(parent,v);
//     if(size[par1]<size[par2]){
//         parent[par1]=par2;
//         size[par2]+=size[par1];
//     }
//     else{
//         parent[par2]=par1;
//         size[par1]+=size[par2];
//     }
// }



// int minCostConnectPoints(vector<vector<int>> &points)
// {
//     int n = points.size();
//     vector<tuple<int, int, int>> edges;

//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = i + 1; j < n; ++j)
//         {
//             int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//             edges.push_back({dist, i, j});
//         }
//     }

//     sort(edges.begin(), edges.end());

//     vector<int>parent(n+1),size(n+1,1);
//     for(int i=0;i<=n;i++){
//         parent[i]=i;
//     }
//     int mst_cost = 0;
//     int edges_used = 0;

//     for (const auto &[dist, u, v] : edges)
//     {
//         int par1=findup(parent,u);
//         int par2 = findup(parent, v);
//         if(par1!=par2){
//             mst_cost += dist;
//             edges_used++;
//             if (edges_used == n - 1)
//             {
//                 break;
//             }
//         }
//     }

//     return mst_cost;
// }

int main()
{
    vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << fun(points) << endl; // Output: 20
    return 0;
}