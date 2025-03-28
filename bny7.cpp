#include <bits/stdc++.h>

using namespace std;
int substringCalculater(string &s){
    unordered_set<string> substrings;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        string sub = s.substr(i);

        for (int j = 0; j < sub.length(); j++) {
            string subDistinct = sub.substr(0, sub.length() - j);

            if (substrings.find(subDistinct) == substrings.end()) {
                substrings.insert(subDistinct);
                // cout << subDistinct << endl;
                count += 1;
            }
        }
    }
    return count;
}
int main() {
    string s = "kincenvizh";
    
    int res = substringCalculater(s);
    cout << res << endl;

    return 0;
}
// substring calculater