#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n,m;
	for (;;)
	{
		cin>>n>>m;
		if (n==0&&m==0)
			break;
		ll arr[n+1];
		arr[0]=0;
		for (ll i=1;i<=n;i++)
		{
			ll brr[m+1];
			brr[0]=0;
			for (ll j=1;j<=m;j++)
			{
				cin>>brr[j];
				if (j>=2)
					brr[j]=max(brr[j-1],brr[j-2]+brr[j]);
			}
			arr[i]=brr[m];
		}
		for (ll j=1;j<=n;j++)
			if (j>=2)
				arr[j]=max(arr[j-1],arr[j-2]+arr[j]);
		cout<<arr[n]<<endl;
	}
}
