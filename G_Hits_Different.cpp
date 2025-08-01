#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 1;
int dp[N];

int get(int n) {
    int lo = 1, hi = 1e4;
    int ans = 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(n <= mid * (mid + 1) / 2) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 5, dp[3] = 10;

    for(int i=4;i<=N;i++) {
        int curr_row = get(i);
        int rank = i - curr_row * (curr_row - 1) / 2;
        if(curr_row == rank) {
            dp[i] = dp[i - curr_row] + i * i;
        }
        else if(rank == 1) {
            dp[i] = dp[i - curr_row + 1] + i * i;
        }
        else {
            int prev_row = curr_row - 1;
            int ele = i - curr_row;
            int sub = ele - prev_row + 1;
            dp[i] = dp[i - curr_row] + dp[i - curr_row + 1] - dp[sub] + i * i;
        }
    }

    int _;
    cin >> _;
    while (_-->0) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}