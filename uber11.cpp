#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define R return
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
#define gcd __gcd
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 0x3f3f3f3f3f3f3f3fLL;
const int ninf = INT64_MIN;
const int mod = 998244353;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }

int fun(int n, vector<vector<int>> &roads, vector<int>&thief, int k, int start, int end){
    vector<int> adj[n+1];
    for(auto &i : roads) {
        adj[i[0]].push_back(i[1]); 
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(n+1, 0);
    queue<int> q;
    for(auto &i : thief){
        q.push(i);
        vis[i] = 1;
    } 
   int cnt=0;
    while(q.size() && cnt < k){
        int sz=q.size();
        cnt++;
        for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
        }
    }
    queue<int>q2;
    q2.push(start);
    vector<int> dist(n+1, inf);
    dist[start] = 0;
    while(!q2.empty()){
        int node = q2.front();
        q2.pop();
        if(vis[node]) continue;
        for(auto &i : adj[node]){
            if(!vis[i] && dist[i] > dist[node] + 1){
                dist[i] = dist[node] + 1;
                q2.push(i);
            }
        }
    }

    if(dist[end] == inf) return -1;

    return dist[end];

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 9;
    vector<vector<int>> road = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{4,7},{5,7},{5,8},{6,8}};
    vector<int> theif = {1,2};
    int k = 1;
    int start = 0;
    int end = 8;

    int ans = fun(n, road, theif, k, start, end);

    cout<<ans<<"\n";


}