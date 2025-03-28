#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
int findMaxUses(vector<int>& costs,vector<int>& uses, int budget){
    int n = costs.size();
    vector<pii> v;
    set<pii> st;
    for(int i=0;i<n;i++){
        v.push_back({costs[i], uses[i] });
        
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        st.insert({v[i].second, i});
    }

    int l = 0,r = n-1;
    int ans = -1;
    while(l < r){
        if(v[l].first + v[r].first > budget){
            st.erase(st.find({v[r].second, r}));
            r--;
        }
        else{
            ans = max(ans, v[l].second + st.rbegin()->first);
            st.erase(st.find({v[l].second,l}));
            l++;
        }
    }

    return ans;
}
int main(){

    int budget = 10;
    vector<int> costs = {7, 5, 4, 2};
    vector<int> uses = {12, 10, 8, 5};
     // output = 18
    int ans = findMaxUses(costs, uses, budget); 

    cout<<ans<<"\n";


    return 0;
}