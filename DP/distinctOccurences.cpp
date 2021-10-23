#include <bits/stdc++.h>
using namespace std;
 
int subsequenceCount(string S, string T);

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		cout<<subsequenceCount(s,tt)<<endl;
		
		
	}
  
}// } Driver Code Ends

/*You are required to complete this method*/


int subsequenceCount(string S, string T)
{ 
    // cout<<S<<" "<<T<<"\n";
  int m = S.length();
  int n = T.length();
  long long int dp[m+1][n+1];
  dp[0][0]=1;
  for(int i=1;i<=m;i++){
      dp[i][0]=1;
  }
  for(int i=1;i<=n;i++){
      dp[0][i]=0;
  }
//   dp[0][0]=1;
  
  for(int i=1;i<=m;i++){
  for(int j=1;j<=n;j++){
      if(i==0){
          dp[i][j]=0;
      }
      else if(j==0){
          dp[i][j]=1;
      }
      else if(S[i-1]!=T[j-1]){
          dp[i][j]=(dp[i-1][j])%1000000007;
      }
      else{
          dp[i][j]=((dp[i-1][j])%1000000007 + (dp[i-1][j-1])%1000000007)%1000000007;
      }
  }
  
  }
 
      
  return dp[m][n]%1000000007;
}
