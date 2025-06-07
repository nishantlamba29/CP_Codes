#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    for(int i=0;i<n;i++) {
        if(a[i] == 'o' && b[i] == 'o') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";


    return 0;
}