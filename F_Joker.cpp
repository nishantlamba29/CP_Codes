#include "bits/stdc++.h"
using namespace std;
#define int long long

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> range = {{m,m}};

    auto fun = [&](int x){
        vector<vector<int>> t1;
        for(auto &i : range){
            int l = i[0], r = i[1];
            if(x >= l && x <= r){
                if(l != r){
                    t1.push_back({l, r});
                }
                t1.push_back({1,1});
                t1.push_back({n,n});
            }
            else if(x < l) t1.push_back({l-1, r});
            else if(r < x) t1.push_back({l, r+1});
        }
        sort(t1.begin(), t1.end());
        vector<vector<int>> t2;
        t2.push_back(t1[0]);
        for(int i=1;i<t1.size();i++){
            if(t1[i][0] <= t2.back()[1]) {
                t2.back()[1] = max(t2.back()[1], t1[i][1]);
            }
            else t2.push_back(t1[i]);
        }
        return t2;
    };

    for(int _=0;_<q;_++){
        int x;
        cin>>x;
        range = fun(x);
        int ans = 0;
        for(auto i : range){
            ans += (i[1] - i[0] + 1);
        }
        cout<<ans<<" ";
    }
    cout<<"\n";

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    for(int __=0;__<_;__++) solve();

    return 0;
}