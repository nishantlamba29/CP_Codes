#include "bits/stdc++.h"
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        char arr[3][3];
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>arr[i][j];
        bool flag = 0;
        for(int i=0;i<3;i++){
            if(flag) break;
            vector<int> f(3,0);
            for(int j=0;j<3;j++){
                if(arr[i][j] != '?')
                f[arr[i][j] - 'A']++;
            }
            for(int i=0;i<3;i++){
                if(f[i] == 0){
                    flag = 1;
                    char ans = 'A'+i;
                    cout<<ans<<"\n";
                }
            }
        }
    }
}