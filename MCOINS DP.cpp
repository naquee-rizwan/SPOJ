#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll arr[1000001]={0},b[50];
	arr[1]=1;
	ll k,l,m,maxi=-1;
	cin>>k>>l>>m;
	for (ll i=0;i<m;i++)
	{
		cin>>b[i];
		maxi=max(b[i],maxi);
	}
	for (ll i=2;i<=maxi;i++)
		if (!arr[i]||((i-k)>=0&&(!arr[i-k]))||((i-l)>=0&&(!arr[i-l])))
			arr[i]=1;
	for (ll i=0;i<m;i++)
		if (arr[b[i]])
			cout<<"A";
		else
			cout<<"B";
}
