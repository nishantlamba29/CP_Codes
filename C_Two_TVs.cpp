#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> temp;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
        temp.push_back(a);
        temp.push_back(b);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(auto &[a, b] : v) {
        a = lower_bound(temp.begin(), temp.end(), a) - temp.begin();
        b = lower_bound(temp.begin(), temp.end(), b) - temp.begin();
    }
    vector<int> f(2 * n + 2);
    for(auto [a, b] : v) {
        f[a]++;
        f[b+1]--;
    }
    for(int i=1;i<2*n+2;i++) {
        f[i] += f[i-1];
    }

    bool flag = 1;
    for(int i=0;i<2*n+2;i++) {
        if(f[i] > 2) {
            flag = 0;
            break;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");


    return 0;
}