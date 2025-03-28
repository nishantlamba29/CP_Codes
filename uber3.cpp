#include <bits/stdc++.h>
using namespace std;


vector<int> co(vector<int>startAt, vector<int>endAt)
{
  int n = startAt.size();
  vector<int > res(n);
  vector<int>st = startAt;
  vector<int>en = endAt;
  sort(st.begin(), st.end());
  sort(en.begin(), en.end());
  for (int i = 0; i < n; ++i)
  {
    int l = startAt[i], r = endAt[i];
    int ind1 = lower_bound(st.begin(), st.end(), r + 1) - st.begin();
    int ind2 = lower_bound(en.begin(), en.end(), l) - en.begin();
    res[i] = ind1 - ind2 - 1;
  }
  return res;
}
int main(){
    vector<int> a={1,3};
    vector<int> e={5,4};
    vector<int> ans=co(a,e);
   for(auto i:ans){
      cout<<i<<" ";
   }

}