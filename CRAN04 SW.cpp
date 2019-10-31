#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{	
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k,i;
		cin>>n>>k;
		string str;
		cin>>str;
		ll sum=0,ans=0,save[n]={0};
		save[0]=1;
		for (i=0;i<n;i++)
		{
			if (str[i]=='1')
				sum++;
			if (sum>=k)
				ans+=save[sum-k];
			save[sum]++;
		}
		cout<<ans<<endl;
	}
}
