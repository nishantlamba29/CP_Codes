#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    string s;
    cin >> n >> k >> s;

    string best;
    bool first = 1;
    for(int len=1;len<=n;len++) {
        string t = s.substr(0, len);
        while(t.size() < k) t += t;
        t.resize(k);
        if(first || t < best) {
            best = t;
            first = 0;
        }
    }

    cout << best << "\n";


    return 0;
}