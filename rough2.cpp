int rec(int i,int w,vector<int> &values, vector<int> &weights,
vector<vector<int>> &dp){
	  if(i==0){
		  if(w<=weights[0]) return values[0];
		  else return 0;
	  }
     if(dp[i][w]!=-1) return dp[i][w];
	 int s=rec(i-1,w,values,weights,dp);
	 int x=-1e8;
	 if(w>=weights[i]){
		 x=values[i]+rec(i-1,w-weights[i],values,weights,dp);
	 }
     return dp[i][w]=max(x,s);
  }
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
     vector<vector<int>> dp(n,vector<int>(w+1,-1));
	 int ans=rec(n-1,w,values,weights,dp);
	 return ans;
}