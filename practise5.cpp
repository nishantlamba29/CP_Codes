#include<bits/stdc++.h>
using namespace std;


int dfs(int node, vector<int>& photo, vector<int>& dp, vector<vector<int>>& adj){
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto i : adj[node]){
        ans = max(ans, dfs(i, photo, dp, adj));
    }
    return dp[node] = photo[node-1] + ans; // -1 for indexing
}
int getMaxPhotoBeauty(int n, vector<int>& photo, vector<int>& from, vector<int>& to){

    vector<vector<int>> adj(n+1);
    for(int i=0;i<n;i++){
        adj[from[i]].push_back(to[i]);
    }

    vector<int> dp(n+1, -1);
    for(int i=1;i<=n;i++){
        if(dp[i] == -1) dfs(i, photo, dp, adj);
    }

    int res = *max_element(dp.begin(), dp.end());
    return res;

}

int main(){

    int city_nodes = 5;
    vector<int> photo_beauty = {1, 2, 3, 4, 5};
    vector<int> city_from = {1, 2, 3, 2, 4};
    vector<int> city_to = {2, 3, 5, 4, 5};

    int ans = getMaxPhotoBeauty(city_nodes, photo_beauty, city_from, city_to);

    cout<<ans<<"\n";

    return 0;
}