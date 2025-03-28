#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int lcm(int a, int b) {
    return (1LL * a * b / gcd(a, b)) % MOD;
}

int countOperations(vector<int>& p) {
    int n = p.size();
    vector<bool> visited(n, false);
    int result = 1;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int length = 0;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                x = p[x] - 1;
                ++length;
            }
            result = lcm(result, length);
        }
    }
    
    return result % MOD;
}

class Solution {
public:
    void solve (istream& cin, ostream& cout) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        cout << countOperations(p) << endl;
    }
};

int main() {
    Solution solution;
    solution.solve(cin, cout);
    return 0;
}

// permuatation operation