#include<bits/stdc++.h>
using namespace std;


vector<int> fun(vector<int> &start, vector<int> &end, vector<int> &task){
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int n = task.size();
    vector<int> res;
    for(int i=0;i<n;i++){
        if(task[i] >= end.back()){
            res.push_back(-1);
            continue;
        }

        int ind = lower_bound(start.begin(), start.end(), task[i]) - start.begin();
        if(ind != 0 && end[ind-1] > task[i]) {
            res.push_back(0);
        }
        else{
            res.push_back(start[ind] - task[i]);
        }
    }

    return res;
}
int main(){

    vector<int> start = {5, 9, 20, 2};
    vector<int> end = {7, 10 , 30, 3};
    vector<int> task = {6, 7, 35, 1};
    
    vector<int> res = fun(start, end, task);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<"\n";
}