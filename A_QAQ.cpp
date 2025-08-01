#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long t1 = 0, t2 = 0;
    long long ans = 0;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++) {
        if(s[i] == 'Q') {
            ans += t2;
            t1++;
        }
        else if(s[i] == 'A') {
            t2 += t1;
        }
    }

    cout << ans << "\n";


    return 0;
}