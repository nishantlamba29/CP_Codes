#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    map<int, multiset<int>> mp;
    for(int i=0;i<n;i++) {
        int temp, val;
        cin>>temp;
        val = temp;
        multiset<int> st;
        for(int j=2;j*j <= val; j++){
            while(temp % j == 0){
                st.insert(j);
                temp /= j;
            }
        }
        if(temp != 1) st.insert(temp);
        st.erase(1);
        mp[i] = st;
    }
    int ans = 0;
    for(int i=0;i<m;i++) {
        int x, y;
        cin>>x>>y;
        x--; y--;
        for(auto &it : mp[x]){
            if(mp[y].find(it) != mp[y].end()){
                ans++;
                mp[x].erase(mp[x].find(it));
                mp[y].erase(mp[y].find(it));
            }
        }
    }
    cout<<ans<<"\n";


    
    return 0;
}