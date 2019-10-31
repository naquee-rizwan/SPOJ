#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k;
		cin>>n>>k;
		vector <pair<ll,ll> > item;
		for (ll i=1;i<=k;i++)
		{
			ll po;
			cin>>po;
			if (po!=-1)
				item.push_back(make_pair(i,po));
		}
		ll sz=item.size(),result[k+1];
		for (ll i=1;i<=k;i++)
			result[i]=999999;
		result[0]=0;
		for (ll i=0;i<=k;i++)
			for (ll j=0;j<sz;j++)
				if ((i-item[j].first)==0||((i-item[j].first)>0&&result[i-item[j].first]!=999999))
					result[i]=min(result[i],result[i-item[j].first]+item[j].second);
		if (result[k]==999999)
			cout<<-1<<endl;
		else
			cout<<result[k]<<endl;
	}
}
