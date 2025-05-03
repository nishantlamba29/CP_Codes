#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> start(n), end(n), task(n);
    for(int i=0;i<n;i++) cin>>start[i];
    int mx = -1;
    for(int i=0;i<n;i++) {
        cin>>end[i];
        mx = max(mx, end[i]);
    }
    for(int i=0;i<n;i++) cin>>task[i];
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    vector<int> res;
    for(auto ele : task){
        
        if(ele > mx){
            res.push_back(-1);
            continue;
        }
        
        int ff = lower_bound(start.begin(), start.end(), ele) - start.begin();
        
        if(ff > 0 && ele < end[ff-1]){
            res.push_back(0);
        }
        else if(ff < n){
            res.push_back(start[ff] - ele);
        }
        // else{
        //     res.push_back(-1);
        // }
    }
    
    for(auto it : res) cout<<it<<" ";
    cout<<'\n';
}