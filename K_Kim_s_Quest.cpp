#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int N = 2e5 + 5;
int dp[N][3][3][3];
int n;
vector<int> v;
bool check(int a, int b, int c) {
    return (a != -1 && b != -1 && c != -1);
}

int rec(int ind, int p1, int p2, int p3) {

    if(check(p1, p2, p3) && (p1 + p2 + p3) % 2 != 0) return 0;
    if(ind == n) {
        return check(p1, p2, p3);
    }

    int &res = dp[ind][p1+1][p2+1][p3+1];
    if(res != -1) return res;

    int ans = rec(ind + 1, p1, p2, p3);
    ans = (ans + rec(ind + 1, p2, p3, v[ind] % 2)) % mod;
    
    return res = ans;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    v.resize(n);

    for(int i=0;i<=n;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                for(int l=0;l<3;l++) dp[i][j][k][l] = -1;
            }
        }
    }

    for(int i=0;i<n;i++) cin >> v[i];

    cout << rec(0, -1, -1, -1);


    return 0;
}