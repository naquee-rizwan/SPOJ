#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(ll arr[],ll n)
{
	pair <ll,ll> solution[n][n];
	for (ll i=0;i<n;i++)
	{
		solution[i][i].first=0;
		solution[i][i].second=arr[i];
	}
	for (ll len=2;len<=n;len++)
	{
		for (ll i=0;i<=n-len+1;i++)
		{
			ll j=i+len-1;
			solution[i][j].first=1000000000000000000;
			for (ll k=i;k<j;k++)
			{
				ll cnt1=solution[i][k].second*solution[k+1][j].second+solution[i][k].first+solution[k+1][j].first;
				ll cnt2=(solution[i][k].second+solution[k+1][j].second)%100;
				if (cnt1<solution[i][j].first)
				{
					solution[i][j].first=cnt1;
					solution[i][j].second=cnt2;
				}
			}
		}
	}
	cout<<solution[0][n-1].first<<endl;
}
int main()
{
	ll n;
	while (cin>>n)
	{
		ll arr[n];
		for (ll i=0;i<n;i++)
			cin>>arr[i];
		solve(arr,n);
	}
}
