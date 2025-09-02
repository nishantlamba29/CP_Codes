#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int x;
    string y;
    cin >> x >> y;
    x--;
    if(v[x] == y) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}