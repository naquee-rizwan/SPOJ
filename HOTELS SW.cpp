#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n,k,maxi=0;
	cin>>n>>k;
	ll j=0,arr[n],sum=0;
	for (ll i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		while (sum>k)
		{
			sum-=arr[j];
			j++;
		}
		maxi=max(maxi,sum);
	}
	cout<<maxi<<endl;
}
