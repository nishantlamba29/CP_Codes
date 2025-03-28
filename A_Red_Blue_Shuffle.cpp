#include<bits/stdc++.h>
using namespace std;
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        int n;
        scanf("%d",&n);
        string a,b;
        cin>>a>>b;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i] > b[i]) cnt++;
            else if(a[i] < b[i]) cnt--;
        }
        if(cnt > 0) printf("RED\n");
        else if(cnt < 0) printf("BLUE\n");
        else printf("EQUAL\n");
    }
}