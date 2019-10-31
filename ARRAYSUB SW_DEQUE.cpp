#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for (ll j=0;j<n;j++)
		cin>>arr[j];
	ll k;
	cin>>k;
	deque <ll> d(k);
	ll i;
	for (i=0;i<k;i++)
	{
		while (!d.empty()&&arr[i]>=arr[d.back()])
			d.pop_back();
		d.push_back(i);
	}
	for (;i<n;i++)
	{
		cout<<arr[d.front()]<<" ";
		while (!d.empty()&&d.front()<=i-k)
			d.pop_front();
		while (!d.empty()&&arr[i]>=arr[d.back()])
			d.pop_back();
		d.push_back(i);
	}
	cout<<arr[d.front()];
}
