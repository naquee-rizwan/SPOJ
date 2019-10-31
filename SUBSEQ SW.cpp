#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll ritesh;
	scanf("%lld",&ritesh);
	for (ll ankit=0;ankit<ritesh;ankit++)
	{
		map <ll,ll> laddu;
		laddu[0]++;
		ll rizwan,ans=0,sum=0;
		scanf("%lld",&rizwan);
		for (ll i=0;i<rizwan;i++)
		{
			ll num;
			scanf("%lld",&num);
			sum+=num;
			ans+=laddu[sum-47];
			laddu[sum]++;
		}
		cout<<ans<<endl;
	}
}
