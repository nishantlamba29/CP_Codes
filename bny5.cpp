#include <bits/stdc++.h>
using namespace std;

int longestChain(int n, vector<string>& words) {
    unordered_set<string> word_set(words.begin(), words.end());
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });
    
    unordered_map<string, int> dp;
    int max_chain = 0;
    
    for (const string& word : words) {
        dp[word] = 1;
        for (int i = 0; i < word.size(); ++i) {
            string new_word = word.substr(0, i) + word.substr(i + 1);
            if (word_set.find(new_word) != word_set.end()) {
                dp[word] = max(dp[word], dp[new_word] + 1);
            }
        }
        max_chain = max(max_chain, dp[word]);
    }
    
    return max_chain;
}

int main() {
    int n = 6;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = longestChain(n, words);
    cout << result << endl;  // Output: 4
    return 0;
}

// longest chain dictionary test
