#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> v(q);
    for(int i=0;i<q;i++) cin >> v[i];

    vector<int> f(n+1, 0);
    for(int i=0;i<q;i++) {
        if(v[i] >= 1) {
            f[v[i]]++;
            cout << v[i] << " ";
        }
        else {
            int mini = 105;
            int ind = -1;
            for(int i=1;i<=n;i++) {
                if(f[i] < mini) {
                    mini = f[i];
                    ind = i;
                }
            }
            cout << ind << " ";
            f[ind]++;
        }
    }

    return 0;
}