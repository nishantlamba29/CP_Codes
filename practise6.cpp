#include<bits/stdc++.h>
using namespace std;

vector<int> getNewPermutation(vector<int> difficulty){
    int n = difficulty.size();
    map<int,int> mp;
    for(auto i : difficulty){
        mp[i]++;
    }
    set<int> st, temp;
    for(int i=0;i<n;i++){
        if(mp[i+1] == 0) st.insert(i+1);
    }
    for(int i=0;i<n;i++){
        if(difficulty[i] > n){
            mp[difficulty[i]]--;
            difficulty[i] = *st.begin();
            st.erase(st.begin());
            temp.insert(difficulty[i]);
            continue;
        }
        if(mp[difficulty[i]] == 1) continue;

        if(temp.find(difficulty[i]) != temp.end()){
            mp[difficulty[i]]--;
            difficulty[i] = *st.begin();
            st.erase(st.begin());
            temp.insert(difficulty[i]);
        }
        else{
            if(*st.begin() <= difficulty[i]){
                mp[difficulty[i]]--;
                difficulty[i] = *st.begin();
                st.erase(st.begin());
            }
            temp.insert(difficulty[i]);
        }
    }
    
    return difficulty;
}

int main(){

    vector<int> difficulty = {3, 40, 1, 2, 2};

    vector<int> ans = getNewPermutation(difficulty);

    for(auto i :  ans) cout<<i<<" ";
    cout<<"\n";

    return 0;
}