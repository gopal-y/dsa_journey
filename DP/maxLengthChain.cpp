// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
bool customSort(struct val a,struct val b){
    if(a.second!=b.second) return a.second<b.second;
    else return a.first<b.first;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
int *dp=new int[sizeof(int)*n];
for(int i = 0; i<n;i++){
    dp[i]=1;
}
sort(&p[0],&p[n],customSort);
for(int i =1;i<n;i++){
    for(int j=0;j<i;j++){
        if(p[i].first>p[j].second && dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
        }
    }
}

int maxx=dp[0];
for(int i=1;i<n;i++){
    if(maxx<dp[i]) maxx=dp[i];
}
return maxx;
}
