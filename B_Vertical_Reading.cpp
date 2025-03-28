#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
#define gcd __gcd

int dp[101][101];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    for (int w = 1; w < n; ++w) {
        for (int c = 1; c <= w; ++c) {
            string res = "";
            for (int i = 0; i * w + c - 1 < n; ++i) {
                if (i * w + c - 1 < n) {
                    res += s[i * w + c - 1];
                }
            }
            if (res == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
