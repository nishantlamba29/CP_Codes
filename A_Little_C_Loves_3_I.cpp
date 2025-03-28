#include "iostream"
main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin>>n;
    int r = n%3;
    if(r == 0 || r == 1){
        std::cout<<"1 1 "<<n-2;
    }
    else{
        std::cout<<"1 2 "<<n-3;
    }
}