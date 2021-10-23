// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;
        
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends

//Complete this function
bool comp(int a, int b) 
{ 
    return (a < b); 
} 
bool comp2(int a, int b) 
{ 
    return (a > b); 
}

int cuts(int n, int x, int y, int z,int *dp)
{
    //Your code here
    // if (n==0){
    //     return 0;
    // }
    // else if(n<0){
    //     return -1;
    // }
    // // cout<<n;
    // if(dp[n]!=-1){
    //     return dp[n];
    // }
    // int a = max({cuts(n-x,x,y,z,dp),cuts(n-y,x,y,z,dp),cuts(n-z,x,y,z,dp)},comp);
    // if(a!=-1){
    //     dp[n]=a+1;
    // }
    // return dp[n];
    dp[0]=0;
    
    for(int i =0;i<=n;i++){
        if(dp[i]==-1){continue;}
        if(i+x<=n){
            dp[i+x]=max(dp[i+x],dp[i]+1);
        }
        if(i+y<=n){
            dp[i+y]=max(dp[i+y],dp[i]+1);
        }
        if(i+z<=n){
            dp[i+z]=max(dp[i+z],dp[i]+1);
        }
    }
    
    return dp[n];
}
int maximizeTheCuts(int n,int x,int y,int z){
    
    int dp[n+1];
    memset(&dp,-1,sizeof(dp));
    dp[0]=0;
    return max(0,cuts(n,x,y,z,&dp[0]));
}
