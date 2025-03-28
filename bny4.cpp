#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}
    int countVowelSubstrings(string word) {
        int n=word.size();
    int ans=0;
    unordered_set<char>st;
    for(int i=0;i<n;i++)
    {
        if(!isVowel(word[i])) continue;  
        for(int j=i;j<n;j++)  
        {
            if(isVowel(word[j]))  
            {
                st.insert(word[j]);
                if(st.size()==5) ans++;  
            }
            else 
            {
                break;
            }
        }
        st.clear(); 
    }
    return ans;
    }


int main() {
    string s = "aeioaexaaeuiou";
    string t = "aaeiouxa";
    cout << countVowelSubstrings(t) << endl; // Output the number of qualifying substrings
    return 0;
}

//   vowel substring