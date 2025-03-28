#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void n_lamba_29(){
    int n,m,k;
    string s;
    cin>>n>>m>>k>>s;
    s = s + 'L';
    int cnt = 0;
    // n++;
    int start = -1;
    for(int i=0;i<=min(m, n);i++){
        if(s[i] == 'L') start = i;
    }
    if(start == -1){
        for(int i=min(m,n);i>=0;i--){
            if(s[i] == 'W'){
                start = i;
                cnt++;
                break;
            }
            else if(s[i] == 'C'){
                cout<<"NO\n";
                return;
            }
        }
    }

    for(int i=start;i<=n;i++){
        int t1 = i;
        if(s[i] == 'L'){
            for(int j=i+1;j<=min(m+i, n);j++){
                if(s[j] == 'L') t1 = j;
            }
        }
        if(t1 != i) {
            i = t1;
            continue;
        }
        int t2 = i;
        if(s[i] == 'L'){
            for(int j = min(n,i+m);j>i;j--){
                if(s[j] == 'W'){
                    t2 = j;
                    cnt++;
                    break;
                }
                else if(s[j] == 'C'){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        if(t2 != i){
            i = t2;
        }
    }

    if(cnt > k) cout<<"NO\n";
    else cout<<"YES\n";
    return;

}

inline void solve(){
    int n,m,k;
    string s;
    cin>>n>>m>>k>>s;
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt++;
        if(s[i] == 'L'){
            cnt = 0;
        }
        if(cnt >= m){
            k--;
            if(s[i] == 'C'){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<< (k >= 0 ? "YES\n" : "NO\n");
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    // n_lamba_29();
    solve();

    return 0;
}
// Nishant ...
