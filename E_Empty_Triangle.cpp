#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29(){
    int n;
    cin >> n;
    vector<int> v = {1, 2, 3};
    while(1) {
        cout << "? " << v[0] << " " << v[1] << " " << v[2] << endl;
        int res;
        cin >> res;
        if(res == 0) {
            cout << "! " << v[0] << " " << v[1] << " " << v[2] << endl;
            return;
        }
        int i = rand() % 3;
        v[i] = res;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}
