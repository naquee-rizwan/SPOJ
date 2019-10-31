#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,c,arr[100000];
ll check(ll mid)
{
	ll pos=arr[0],cows=1;
	for (ll i=1;i<n;i++)
		if (arr[i]-pos>=mid)
		{
			pos=arr[i];
			cows++;
			if (cows==c)
				return 1;
		}
	return 0;
}
ll binary_search()
{
	ll start=0,end=arr[n-1],maxi=-1;
	while (end>start)
	{
		ll mid=start+(end-start)/2;
		if (check(mid)==1)
		{
			maxi=max(maxi,mid);
			start=mid+1;
		}
		else
			end=mid;
	}
	return maxi;
}
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		cin>>n>>c;
		for (ll i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		cout<<binary_search()<<endl;
	}
}

