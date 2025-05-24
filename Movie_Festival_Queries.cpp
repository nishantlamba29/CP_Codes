#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int inf = 1e9;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> time(N, inf);
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        time[a] = min(time[a], b);
    }

    for(int i=N-2;i>=0;i--) {
        time[i] = min(time[i], time[i+1]);
    }
    
    vector<vector<int>> table(21, vector<int>(N, inf));
    for(int i=0;i<N;i++) {
        table[0][i] = time[i];
    }

    for(int j=1;j<=20;j++) {
        for(int i=1;i<N;i++) {
            if(table[j-1][i] != inf)
            table[j][i] = table[j-1][table[j-1][i]];
            else table[j][i] = inf;
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        int curr = a;
        for(int i=20;i>=0;i--) {
            int next = table[i][curr];
            if(next <= b) {
                ans += (1 << i);
                curr = next;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}