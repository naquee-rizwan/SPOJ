#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t[200000001],cub[70];
int main()
{
	for(ll i=1;i<70;i++)
        cub[i]=i*i*i;
	for (ll i=2;i<=200000000;i++)
		t[i]=t[i-2]+cub[__builtin_ffsl(i*(i-1))];
	ll q;
	scanf ("%lld",&q);
	for (ll i=0;i<q;i++)
	{
		ll n;
		scanf ("%lld",&n);
		printf ("%lld\n",t[n]);
	}
}
