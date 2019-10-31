#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while (t--)
	{
		ll n;
		scanf("%lld",&n);
		ll arr[n],maxi=-10000;
		for (ll i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			maxi=max(maxi,arr[i]);
		}
		if (maxi<=0)
		{
			unordered_map <ll,ll> m;
			m[0]++;
			ll ans=0,sum=0;
			for (ll i=0;i<n;i++)
			{
				sum+=arr[i];
				ans+=m[sum-maxi];
				m[sum]++;
			}
			printf ("%lld %lld\n",maxi,ans);
		}
		else
		{
			ll maxu=-1,sum=0,ans=0;
			for (ll i=0;i<n;i++)
			{
				sum+=arr[i];
				if (sum<=0)
					sum=0;
				maxu=max(maxu,sum);
			}
			unordered_map <ll,ll> m;
			m[0]++;
			sum=0;
			for (ll i=0;i<n;i++)
			{
				sum+=arr[i];
				ans+=m[sum-maxu];
				m[sum]++;
			}
			printf ("%lld %lld\n",maxu,ans);
		}
	}
}
