/*
⠈⠙⠲⢶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⡀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⣼⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⠟⠓⠉
⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⢀⣧⣶⣦⣇⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣾⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠛⠛⠛⠛⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠟⠛⠛⠛⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀⠀
*/
#include<bits/stdc++.h>
using namespace std;
// Nishant Lamba...
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
#define gcd __gcd
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e17;
const int ninf = -1LL*inf;
const int mod = 998244353;
class DSU{ public: vec parent, size;
DSU(int n){  parent.resize(n+1); iota(all(parent) ,0); size.resize(n+1,1); }
int find_par(int x){ if(x == parent[x]) return x; 
    return parent[x] = find_par(parent[x]); }
bool union_set(int u, int v){
    int p1 = find_par(u), p2 = find_par(v); if(p1 == p2) return 0;
    if(size[p1] < size[p2]){ parent[p1] = p2; size[p2] += size[p1]; }
    else{ parent[p2] = p1; size[p1] += size[p2]; } return 1;} };
bool check(int nx, int ny, int n, int m){  return (nx>=0 && ny>=0 && nx<n && ny<m); }
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
int powr(int a, int b){ int res = 1; while(b>0){ if(b&1) res *= a; a *= a; b = b>>1; } return res;}
int modpowr(int a, int b, int k){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}
int nCr(int n, int r){ if(n<r) return 0; if(r > n-r) r = n-r; int res = 1;
    for(int i=1;i<r+1;i++) {res *= (n-r+i); res /= i;} return res;}
vector<int> isPrime, spf;
void seive(int N = 1e6){ isPrime.resize(N+1,1); isPrime[0]=0; isPrime[1]=0;
    for(int i=2;i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j] = 0;}
void SPF(int N = 1e6){ spf.resize(N+1); iota(all(spf),0);
    for(int i=2;i*i<=N;i++) if(spf[i] == i) for(int j=i*i;j<=N;j+=i) spf[j] = min(spf[j],i);}

inline void n_lamba_29(){
    int n,q;
    cin>>n>>q;
    vector<int> change(n+q+2, 0);
    DSU ds(n+q);
    vector<vector<int>> edges;
    vector<vector<int>> events;
    for(int i=1;i<=q;i++){
        int l,r,c;
        cin>>l>>r>>c;
        // events.push_back({l, 0, n+i, c});
        // events.push_back({r+1, 1, n+i, c});
        for(int j=l;j<=r;j++){
            edges.push_back({n+i, j, c});
        }
        // change[l] += c;
        // change[r+1] -= c;
    }
    // sort(all(events));
    set<int> st;
    // for(int i=0;i<events.size();i++){
    //     int time = events[i][0];
    //     int type = events[i][1];
    //     int u = events[i][2];
    //     int cost = events[i][3];

    //     if(type == 0){
    //         for(int j : st){
    //             edges.push_back({u, j, cost});
    //         }
    //         st.insert(time);
    //     }
    //     else{
    //         st.erase(st.find(time-1));
    //     }


    // }
    // for(int i=1;i<=n;i++){
    //     change[i] += change[i-1];
    //     edges.push_back({n+i, i, change[i]});
    // }
    
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });

    int cost = 0;
    for(auto &i : edges){
        if(ds.union_set(i[0], i[1])){
            cost += i[2];
        }
    }
    int cnt = 0;
    for(int i=1;i<=n+q;i++){
        if(ds.parent[i] == i) cnt++;
        if(cnt > 1){
            cout<<-1<<"\n";
            return;
        }
    }
    cout<<cost<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();

    return 0;
}
// Nishant ...