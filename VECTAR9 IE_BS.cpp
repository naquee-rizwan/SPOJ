#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll v[13]={2,3,5,7,11,13,17,19,23,29,31,37,41},arr[8192];
ll k,upto=8192;
ll check(ll mid)
{
    ll ans=0;
    for (ll i=1;i<upto;i++)
        ans+=(mid/arr[i]);
    return ans;
}
int main(){
	int t;
	scanf("%lld",&t);
	for (ll i=1;i<upto;i++)
    {
        ll j=i,cnt=0,cnt2=0,mult=1;
        while (j)
        {
            if (j&1)
            {
                cnt2++;
                mult*=v[cnt];
            }
            cnt++;
            j>>=1;
        }
        if (cnt2%2)
            arr[i]=mult;
        else
            arr[i]=-mult;
    }
	for (ll rizwan=0;rizwan<t;rizwan++)
	{
		scanf("%lld",&k);
		ll l=0,r=1000000000000000000ll,ans=0;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			ll tt=check(mid);
			if(tt>=k)
			{
				r=mid-1;
				ans=mid;
			}
			else
				l=mid+1;
		}
		printf("%lld\n",ans);
	}
}
