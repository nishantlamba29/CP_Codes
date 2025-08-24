#include <bits/stdc++.h>
using namespace std;
#define int long long
class Fenwick {
    int n;
    vector<int> bit;
public:
    Fenwick(int n) {
        this->n = n;
        bit = vector<int>(n+1, 0);
    }

    void update(int id, int val) {
        while(id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }

    int query(int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= id & -id;
        }
        return ans;
    }

};
inline void n_lamba_29() {

    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(n+1),b(m+1);
    vector<pair<int,int>>c;
    // c.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c.push_back({a[i],i});
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        c.push_back({b[i],i+n});
    }
    sort(a.begin()+1,a.end());
    reverse(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    reverse(b.begin()+1,b.end());
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());

    Fenwick fen1(n+m+1);
    Fenwick fen2(n+m+1);
    for(int i=0;i<c.size();i++){
        if(c[i].second<=n){
            fen1.update(i+1,1);
        }
        else{
            fen2.update(i+1,1);
        }
    }
    vector<int>pa(n+1),pb(m+1),pc(n+m+1);
    for(int i=1;i<=n;i++){
        pa[i]=pa[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        pb[i]=pb[i-1]+b[i];
    }
    for(int i=1;i<=(n+m);i++){
        pc[i]=pc[i-1]+c[i-1].first;
    }
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        int cnt1=fen1.query(z);
        int cnt2=fen2.query(z);
        // cout<<"cnt1 "<<cnt1<<" "<<"cnt2 "<<cnt2<<endl;
        if(cnt1<=x && cnt2<=y){
            cout<<pc[z]<<endl;
        }
        else{
            int maxi=0;
            if(z-x>=0){
                maxi=pa[x]+pb[z-x];
            }
            if(z-y>=0){
                maxi=max(maxi,pa[z-y]+pb[y]);
            }
            
            cout<<maxi<<endl;
        }
    }
}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}