// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends

// function to count number of ways to reach top of the stair
long long countWays(int n){
    
    // your code here
    if(n==1){
        return 1;
    }
    else if(n<=0){
        return 0;
    }
long long int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    if(n>3){
    for(int i=4;i<=n;i++)
        dp[i]=(dp[i-1]%1000000007 + dp[i-2]%1000000007 +dp[i-3]+1000000007)%1000000007;
        // cout<<i<<" "<<dp[i]<<"\n";}
        
    }
    return dp[n]%1000000007;
}
