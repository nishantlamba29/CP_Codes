#include<bits/stdc++.h>
using namespace std;

string palindromeChecker(string s, vector<int> startIndex, vector<int> endIndex, vector<int> subs) { 
        int n = s.length();
        vector<vector<int>> queries;
        for(int i=0;i<startIndex.size();i++){
            queries.push_back({startIndex[i], endIndex[i], subs[i]});
        }
        vector<vector<int>> count(n+1, vector<int>(26, 0));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<26; j++) {
                count[i][j] += count[i-1][j] + (s[i-1]==('a'+j));
            }
        }

        vector<int> ans;
        string temp;
        for(auto i: queries) {

            int start = i[0]+1;
            int end = i[1]+1;
            int k = i[2];
            int remaining = (end-start+1);
            int oddCount = 0;
            
            for(int j=0; j<26; j++) {
                int tp = count[end][j]-count[start-1][j];

                remaining -= (tp - (tp&1));
                oddCount += tp&1;

            }
            if((end-start+1)%2==1 && oddCount>=1) {
                remaining--;
            }
             

            if((remaining+1)/2 <=k ) {
                temp.push_back('1');
                ans.push_back(1);

            } else {
                temp.push_back('0');
                ans.push_back(0);
            }

        }
        return temp;
}

int main(){
    string s = "cdecd"; // bcbab
    vector<int> startIndex = {0,0,0,0}; // 1 1 2
    vector<int> endIndex = {0, 1, 2, 3}; // 4 3 3
    vector<int> subs = {0, 1, 1, 0}; //3 3 0
        // output     110

    string t = "bcbab";
    vector<int> f1 = {1,1,2}, f2 = {4,3,3}, f3 = {3,3,0};
    string res = palindromeChecker(t, f1, f2, f3);
    cout<<res<<"\n";
    // for(auto i : res) cout<<i;

    return 0;
}

// palindrome checker