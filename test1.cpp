#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    queue<int> q;
    q.push(1);
    unordered_map<int, int> mp;
    int maxi = 0;
    while(q.size()){
        int curr = q.front();
        q.pop();
        int t1 = curr*a;
        int t2 = curr*b;
        int t3 = curr+c;
        if(t1 <= d && mp.find(t1) == mp.end()){
            mp[t1]++;
            q.push(t1);
            maxi = max(maxi, t1);
        }
        if(t2 <= d && mp.find(t2) == mp.end()){
            mp[t2]++;
            q.push(t2);
            maxi = max(maxi, t2);
        }
        if(t3 <= d && mp.find(t3) == mp.end()){
            mp[t3]++;
            q.push(t3);
            maxi = max(maxi, t3);
        }
    }
    cout<<maxi<<"\n";

    return 0;
}