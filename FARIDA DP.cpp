#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t,x=1;
	cin>>t;
	while (t--)
	{
		ll n;
		cin>>n;
		ll arr[n+1];
		arr[0]=0;
		for (ll i=1;i<=n;i++)
		{
			cin>>arr[i];
			if(i>=2)
				arr[i]=max(arr[i]+arr[i-2],arr[i-1]);
		}
		cout<<"Case "<<x<<": "<<arr[n]<<endl;
		x++;
	}
}
