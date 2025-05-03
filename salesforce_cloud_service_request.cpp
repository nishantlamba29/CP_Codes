#include <bits/stdc++.h>
using namespace std;


int minRequestTime(int n, int m, vector<int> time, vector<int> req) {
    // m total servers time.size()
    // n = requests req.size()
    
    vector<int> dist(m+1), dist1(m+1);
    dist[0] = 0;
    for(int i=1;i<m;i++) {
        dist[i] = dist[i-1] + time[i-1];
    }
    dist1[0] = 0;
    for(int i=m-1;i>0;i--) {
        dist1[i] = dist1[i+1] + time[i];
    }
    int ans = 0;
    int prev = 0;

    for(int i=0;i<n;i++) {
        int curr = req[i];
        curr--;
        ans += min(abs(dist[curr] - dist[prev]), abs(dist1[curr] - dist1[prev]));
        prev = curr;
    }

    return ans;


}

int main() {
    int n = 4, m = 3;
    vector<int> time = {3, 2, 1};
    vector<int> reqserver = {3, 2, 2, 1};

    int ans = minRequestTime(n, m, time, reqserver);
    cout << ans << "\n";

}