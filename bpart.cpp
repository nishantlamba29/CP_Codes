#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<set<int>> dp(K + 1);
    dp[0].insert(0);
    
    for (int num : A) {
        for (int j = K; j >= 1; --j) {
            for (int sum : dp[j - 1]) {
                dp[j].insert(sum + num);
            }
        }
    }
    
    
    int maxMultiple = -1;
    for (int sum : dp[K]) {
        if (sum % M == 0) {
            maxMultiple = max(maxMultiple, sum);
        }
    }
    
    cout << maxMultiple << endl;
    
    return 0;
}
