#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;

    vector<vector<vector<int> > >a(n,vector<vector<int> >(m,vector<int>(3,0)));
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            for(int l=0;l<3;l++)
            {
                cin>>a[i][j][l];
            }
        }
    }
    // vector<int>v(m,0);
    // for(int j=0;j<m;j++)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         v[j]=max(v[j],a[i][j][1]);
    //     }
    // }
    // for(int i=0;i<m;i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    int ans=0;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        vector<vector<int> >t;
        for(int l=0;l<m;l++)
        {
            if(a[j][l][1]-a[i][l][0]>0)
            t.push_back({a[j][l][1]-a[i][l][0],a[i][l][2]});
        }
        
       
        sort(t.begin(),t.end());
        int p=0,o=t.size()-1,u=k;
        while(o>=0&&u-t[o][1]>=0)
        {
            p+=t[o][1]*t[o][0];
        
            u-=t[o][1];
            o--;
        }
        if(o>=0)
        {
            p+=u*t[o][0];
        }
        ans=max(ans,p);
       
    }
   }
   cout<<ans<<endl;
   }