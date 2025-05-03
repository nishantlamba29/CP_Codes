#include<bits/stdc++.h>
using namespace std;
#define int long long

inline string tobin(int n){
    string s = "";
    while(n != 0){
        s += (n&1 ? '1' : '0');
        n = n>>1;
    }
    reverse(s.begin(), s.end());
    return s;
}
vector<int> v = {0,1};

inline void sol(){
    for(int i=0;i<(1<<15);i++){

        string t1 = tobin(i);
        string t2 = t1;
        reverse(t2.begin(), t2.end());

        vector<string> temp = {t1+t2, t2+t1, t1+"0"+t2, t1+"1"+t2, t2+"1"+t1, t2+"0"+t1};
        for(auto &i : temp){
            if(i[0] == '1'){
                v.push_back(stoll(i,NULL,2));
            }
        }
    }
    sort(v.begin(),v.end());
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sol();
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int ind = lower_bound(v.begin(), v.end(), n) - v.begin();
        int ans = v[ind] - n;
        if(ind > 0) ans = min(ans, (n-v[ind-1]));

        cout<<ans<<"\n";
    }

    return 0;
}