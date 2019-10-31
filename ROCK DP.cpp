#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solution(string str,ll n)
{
	ll solve[n][n];
	ll prefix[n+1]={0};
	for (ll i=0;i<n;i++)
		if (str[i]=='1')
		{
			solve[i][i]=1;
			prefix[i+1]=prefix[i]+1;
		}
		else
		{
			solve[i][i]=0;
			prefix[i+1]=prefix[i];
		}
	for (ll len=2;len<=n;len++)
	{
		for (ll i=0;i<=n-len;i++)
		{
			ll j=i+len-1;
			solve[i][j]=-1000000000000000000;
			ll ones=prefix[j+1]-prefix[i];
			ll zeroes=len-ones;
			if (ones>zeroes)
				solve[i][j]=len;
			else
				for (ll k=i;k<j;k++)
					solve[i][j]=max(solve[i][j],solve[i][k]+solve[k+1][j]);
		}
	}
	cout<<solve[0][n-1]<<endl;
}
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n;
		cin>>n;
		string str;
		cin>>str;
		solution(str,n);
	}
}
