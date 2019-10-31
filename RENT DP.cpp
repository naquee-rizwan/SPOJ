#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t;
	scanf ("%lld",&t);
	for (ll typo=0;typo<t;typo++)
	{
		ll n;
		scanf ("%lld",&n);
		vector <pair<pair<ll,ll>,ll> > pr;
		for (ll i=0;i<n;i++)
		{
			ll s,d,p;
			scanf ("%lld%lld%lld",&s,&d,&p);
			pr.push_back(make_pair(make_pair(d+s,s),p));
		}
		sort(pr.begin(),pr.end());
		ll arr[n];
		for (ll i=0;i<n;i++)
			arr[i]=pr[i].second;
		for (ll i=1;i<n;i++)
			for (ll j=0;j<i;j++)
				if (pr[j].first.first<=pr[i].first.second)
					arr[i]=max(arr[i],arr[j]+pr[i].second);
		ll maxi=-1000000000000000000;
		for (ll i=0;i<n;i++)
			maxi=max(maxi,arr[i]);
		printf ("%lld\n",maxi);
	}
}
