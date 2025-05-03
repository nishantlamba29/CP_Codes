#include<bits/stdc++.h>
using namespace std;
#define int long long
int fun(int n, vector<vector<int>>& score){
    vector<int> ind(10);
    int start = -1;
    int gmax = INT_MIN;
    for(int i=0;i<10;i++){
        vector<int> t = score[i];
        int maxi = INT_MIN;
        for(int j=0;j<10;j++){
            if(maxi < t[j]){
                maxi = t[j];
                ind[i] = j;
            }
        }
        if(gmax < maxi){
            gmax = maxi;
            start = i;
        }

    }
    int ans = 0;
    int prev  = start;
    for(int i=0;i<n-1;i++){
        ans += score[prev][ind[prev]];
        prev = ind[prev];

    }
    return ans;

}
int32_t main(){
    int n;
    cin>>n;
     vector<vector<int>> arr = {{1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, 2000},//2000
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, -200}, // -200
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
                                {2, 4, 6, 8, 0, 2, 4, 6, 8, 0},
                                {1, 0, 1, 0, 1, 0, 1, 0, 1, 1000}}; // 1000
    
    n  = 3; // ans = 3000 ; array = [3, 9, 9];
    int ans = fun(n, arr);
    
    cout<<ans<<"\n";


    return 0;
}