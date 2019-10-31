#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct quest
{
	ll start,finish,profit;
};
ll cmp(quest a,quest b)
{
	return a.finish<b.finish;
}
ll binary_search(quest arr[],ll left,ll right,ll find)
{
	if (arr[right].finish<=find)
		return right;
	if (arr[left].finish>find)
		return -1;
	ll mid=left+(right-left)/2;
	if (arr[mid].finish==find)
		return mid;
	else if (arr[mid].finish>find)
		if (mid-1>=left&&arr[mid-1].finish<=find)
			return mid-1;
		else
			return binary_search(arr,left,mid-1,find);
	else
		if (mid+1<=right&&arr[mid+1].finish>find)
			return mid;
		else
			return binary_search(arr,mid+1,right,find);
}
int main()
{
	while (1)
	{
		ll t;
		scanf("%lld",&t);
		if (t==-1)
			break;
		quest asd[t];
		for (ll i=0;i<t;i++)
			scanf("%lld%lld",&asd[i].start,&asd[i].finish);
		sort (asd,asd+t,cmp);
		asd[0].profit=1;
		for (ll i=1;i<t;i++)
		{
			ll nsum=0,j=binary_search(asd,0,i,asd[i].start);
			if (j!=-1)
			{
				while ((j+1)<t&&asd[j].finish==asd[j+1].finish)
					j++;
				nsum=asd[j].profit;
			}
			nsum%=100000000;
			nsum++;
			asd[i].profit=(nsum+asd[i-1].profit)%100000000;
		}
		ll store=asd[t-1].profit,cnt=0;
		while (store)
		{
			cnt++;
			store/=10;
		}
		cnt=8-cnt;
		for (ll i=1;i<=cnt;i++)
			printf ("0");
		printf ("%lld",asd[t-1].profit);
		printf("\n");
	}
}
