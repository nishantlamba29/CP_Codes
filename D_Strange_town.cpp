#include <bits/stdc++.h>
using namespace std;

int main(){
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> b;
    vector<int> vis(1001, 0);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<1001;j++) {
            bool flag = 0;
            for(int ele : b) {
                if(j == ele) {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            for(int ele : b) {
                if(vis[ele + j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            for(int ele : b) {
                vis[ele + j] = 1;
            }
            b.push_back(j);
            vis[j] = 1;
            break;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) cout << "0 ";
            else cout << b[i] + b[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}