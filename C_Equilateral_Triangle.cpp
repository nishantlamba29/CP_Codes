#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<int> v(n-1);
    for(int i=0;i<n-1;i++) cin >> v[i];

    if(l % 3 != 0) {
        cout << "0\n";
        return 0;
    }

    vector<int64_t> freq(l, 0);

    int cnt = 0;
    freq[0] = 1;
    freq[v[0]] = 1;
    for(int i=1;i<n-1;i++) {
        v[i] += v[i-1];
        v[i] %= l;
        freq[v[i]]++;
    }

    int64_t ans = 0;
    for(int i=0;i<l;i++) {
        ans += (freq[i] * freq[(i + l / 3) % l] * freq[(i + 2 * l / 3) % l]);
    }
    cout << ans / 3 << "\n";



    return 0;
}