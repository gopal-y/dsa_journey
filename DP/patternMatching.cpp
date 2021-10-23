// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends

/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
    int m=str.length();
    int n=pattern.length();
    if(n==0){
        return m==0;
    }
    bool dp[m+1][n+1];
    memset(&dp,false,sizeof(dp));
    dp[0][0]=true;
    for(int j=1;j<=n;j++){
        if(pattern[j-1]=='*'){
            dp[0][j]=dp[0][j-1];
        }
        
        }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(pattern[j-1]=='*')
                dp[i][j]=dp[i][j-1] || dp[i-1][j];
            else if(pattern[j-1]=='?' || str[i-1]==pattern[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=false;
            }
        }
    }
return dp[m][n];
    }
