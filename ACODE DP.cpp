#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	string t;
	while (cin>>t)
	{
		if (t=="0")
			break;
		ll ar[t.length()];
		ll k=t.length();
		for (ll i=1;i<k;i++)
			ar[i]=0;
		ar[0]=1;
		for (ll i=1;i<k;i++)
		{
			if (t[i]-'0')
				ar[i]=ar[i-1];
			ll num=(t[i-1]-'0')*10+(t[i]-'0');
			if (num>=10&&num<=26)
			{
				if (i==1)
					ar[i]=ar[i]+1;
				else
					ar[i]+=ar[i-2];
			}
		}
		cout<<ar[k-1]<<endl;
	}
}
