// C++ Solution
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solution(vector<vector<int>> &A) {
    int p= A.size(), q= A[0].size();
    vector<long> rowPreSum(p), colPreSum(q);
    int i, j;
    for (i= 0; i < p; i++) {
        rowPreSum[i]= (i > 0)? rowPreSum[i-1] : 0;
        for (j= 0; j < q; j++)
            rowPreSum[i]+= A[i][j];
    }
    for (i= 0; i < q; i++) {
        colPreSum[i]= (i > 0)? colPreSum[i-1] : 0;
        for (j= 0; j < p; j++)
            colPreSum[i]+= A[j][i];
    }
    int rowEqCount= 0, colEqCount= 0;
    for (i= 0; i < p; i++)
        if (rowPreSum[p-1] - rowPreSum[i] == ((i > 0)? rowPreSum[i-1] : 0))
            rowEqCount++;
    for (i= 0; i < q; i++)
        if (colPreSum[q-1] - colPreSum[i] == ((i > 0)? colPreSum[i-1] : 0))
            colEqCount++;
    return (rowEqCount*colEqCount);
}

int main() {
    vector<vector<int>> A{  { 2, 7, 5 }, 
                            { 3, 1, 1 }, 
                            { 2, 1, -7 },
                            { 0, 2, 1 }, 
                            { 1, 6, 8 }  };
    
    cout<< solution(A);
    
    return 0;
}