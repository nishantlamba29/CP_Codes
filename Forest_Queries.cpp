#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j =0 ;j<n;j++){
            char ch;
            cin>>ch;
            if(ch == '*') v[i][j] = 1;
            else v[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j > 0)
            v[i][j] += v[i][j-1];
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(i>0)
            v[i][j] += v[i-1][j];
        }
    }

    for(int i=0;i<q;i++){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;r2--;c1--;c2--;
        int total = v[r2][c2];
        if(r1 > 0)
        total -= v[r1-1][c2];
        if(c1 > 0)
        total -= v[r2][c1-1];
        if(r1 > 0 && c1 > 0)
        total += v[r1-1][c1-1];
        cout<<total<<"\n";
    }

    return 0;
}