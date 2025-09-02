#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    int gg = 0, ones = 0;

    for(int i=0;i<n;i++) {
        cin >> v[i];
        gg = gcd(gg, v[i]);
        if(v[i] == 1) ones++;
    }
    if(gg != 1) {
        cout << "-1\n";
        return 0;
    }
    if(ones) {
        cout << n - ones << "\n";
        return 0;
    }
    int mini = n;
    for(int i=0;i<n;i++) {
        int gg = v[i];
        for(int j=i;j<n;j++) {
            gg = gcd(gg, v[j]);
            if(gg == 1) {
                mini = min(mini, j - i);
            }
        }
    }

    cout << mini + n - 1 << "\n";



    return 0;
}