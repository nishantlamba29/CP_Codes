#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> a = v;
    sort(a.begin(), a.end());
    vector<int> temp;
    for(int i=0;i<n;i++) {
        if(v[i] <= a[k-1]) temp.push_back(v[i]);
    }
    int i = 0, j = temp.size() - 1;
    int cnt = 0;
    while(i < j) {
        if(temp[i] == temp[j]) {
            i++;
            j--;
            cnt += 2;
            continue;
        }
        else if(temp[i] == a[k-1]) {
            i++;
        }
        else if(temp[j] == a[k-1]) {
            j--;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    if(i == j) cnt++;
    if(cnt >= k - 1) cout << "YES\n";
    else cout << "NO\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }

    return 0;
}