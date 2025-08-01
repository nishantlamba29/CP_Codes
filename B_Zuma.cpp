#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int v[N];
int dp[N][N];

int rec(int i, int j) {
    if(i > j) return 0;
    if(i == j) return 1;
    int &res = dp[i][j];
    if(res != -1) return res;

    int val1 = 1 + rec(i + 1, j);
    if(v[i] == v[i+1]) {
        val1 = min(val1, 1 + rec(i+2, j));
    }
    int val2 = INT_MAX;
    for(int k=i+2;k<=j;k++) {
        if(v[k] == v[i]) {
            val2 = min(val2, rec(i+1, k-1) + rec(k+1, j));
        }
    }
    return res = min(val1, val2);

}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) dp[i][j] = -1;
    }

    cout << rec(0, n-1);

    return 0;
}