#include <iostream> 
#include <vector> 
#include <cstring> 
using namespace std; 
const int MAXN = 200001; 
vector<int> tree[MAXN]; 
char C[MAXN]; 
int result[MAXN]; 
bool isPalindrome[MAXN]; 
bool visited[MAXN]; 
bool checkPalindrome(const string& s) { 
    int n = s.size(); 
    for (int i = 0; i < n / 2; ++i) { 
        if (s[i] != s[n - i - 1]) { 
            return false; 
        } 
    } 
    return true; 
} 
string dfs(int u) { 
    visited[u] = true; 
    string S = ""; 
 
    for (int v : tree[u]) { 
        if (!visited[v]) { 
            S += dfs(v); 
        } 
    } 
 
    S += C[u]; 
    isPalindrome[u] = checkPalindrome(S); 
    return S; 
} 
 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
     
    int N; 
    cin >> N; 
 
    for (int i = 1; i < N; ++i) { 
        int u, v; 
        cin >> u >> v; 
        tree[u].push_back(v); 
        tree[v].push_back(u); 
    } 
    for (int i = 1; i <= N; ++i) { 
        cin >> C[i]; 
    } 
 
    memset(visited, false, sizeof(visited)); 
    dfs(1); 
 
    int Q; 
    cin >> Q; 
    while (Q--) { 
        int u; 
        cin >> u; 
        cout << (isPalindrome[u] ? 1 : 0) << "\n"; 
    } 
 
    return 0; 
}