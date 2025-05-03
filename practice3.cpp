#include<bits/stdc++.h>
using namespace std;
#define int long long

int rec(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& score){
    if(i <= 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    for(int k=0;k<10;k++){
        ans = max(ans, rec(i-1, k, dp, score) + score[k][j]);
    }
    return dp[i][j] = ans;

}
int getMaxScore(int n, vector<vector<int>>& score){

    vector<vector<int>> dp(n, vector<int>(10, -1));
    int maxi = 0;
    for(int j=0;j<10;j++){
        maxi = max(maxi, rec(n-1, j, dp, score));
    }

    return maxi;

}


int32_t main(){

     vector<vector<int>> arr = {{1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, 2000}, // 2000
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, -200},  // -200
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {1, 0, 1, 0, 1, 0, 1, 0, 1, 1000}}; // 1000
    
    int n  = 3; // ans = 3000 ; array = [3, 9, 9];

    int ans = getMaxScore(n, arr);
    
    cout<<ans<<"\n";

    return 0;

}