#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<vector<int>> v;
    ordered_set<int> st;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        st.insert(b);
        v.push_back({a, b, i});
    }
    int ind = -1;

    sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++) {
        int r = v[i][1];
        st.erase(r);
        int it = st.order_of_key(r);
        if(it != 0) {
            ind = i;
            break;
        }
    }
    if(ind != -1)
    for(int i=ind+1;i<n;i++) {
        if(v[i][1] <= v[ind][1]) {
            cout << v[i][2] + 1 << " " << v[ind][2] + 1 << "\n";
            return;
        }
    }

    for(int i=0;i<n-1;i++) {
        if(v[i][0] == v[i+1][0]) {
            cout << v[i][2] + 1 << " " << v[i+1][2] + 1 << "\n";
            return;
        }
    }
    
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    
    for(int i=0;i<n-1;i++) {
        if(v[i][1] == v[i+1][1]) {
            cout << v[i+1][2] + 1 << " " << v[i][2] + 1 << "\n";
            return;
        }
    }

    cout << "-1 -1 \n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _ = 1;
    // cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}