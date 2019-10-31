#include<bits/stdc++.h>
#include<stdio.h>
typedef long long ll;
#define cin1(a) scanf("%lld",&a)
#define cin2(a,b) scanf("%lld%lld",&a,&b)
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,t;
	cin2(n,t);
	ll pos=0,neg=0,arr[n];
	for (ll i=0;i<n;i++)
	{
		cin1(arr[i]);
		if (arr[i]>0)
			pos+=arr[i];
		else
			neg+=arr[i];
	}
	bitset <100001> bs;
	bs[-neg]=1;
	for (ll i=0;i<n;i++)
		if (arr[i]>0)
			bs=bs|(bs<<arr[i]);
		else
			bs=bs|(bs>>(-arr[i]));
	ll asd[100001]={0};
	asd[-neg]=1;
	for (ll i=1;i<=100000;i++)
		if (bs[i-neg]==1)
			asd[i-neg]=asd[i-neg-1]+1;
		else
			asd[i-neg]=asd[i-neg-1];
	for (ll typo=0;typo<t;typo++)
	{
		ll left,right;
		cin2(left,right);
		printf ("%lld\n",asd[right]-asd[left-1]);
	}
}
