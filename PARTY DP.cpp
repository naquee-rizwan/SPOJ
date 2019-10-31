#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct item
{
	ll siz,val;
};
int main()
{
	while(1)
	{
		ll s,n;
		cin>>s>>n;
		if (s==0&&n==0)
			break;
		item nsasrr98[n+1];
		for (ll i=1;i<=n;i++)
			cin>>nsasrr98[i].siz>>nsasrr98[i].val;
		ll answer[n+1][s+1];
		for (ll i=0;i<=s;i++)
			answer[0][i]=0;
		for (ll i=0;i<=n;i++)
			answer[i][0]=0;
		item maxi;
		maxi.siz=0;
		maxi.val=10000000000000;
		for (ll i=1;i<=n;i++)
			for (ll j=1;j<=s;j++)
			{
				if (j-nsasrr98[i].siz>=0)
					answer[i][j]=max(answer[i-1][j],answer[i-1][j-nsasrr98[i].siz]+nsasrr98[i].val);
				else
					answer[i][j]=answer[i-1][j];
				if (answer[i][j]>maxi.siz)
				{
					maxi.siz=answer[i][j];
					maxi.val=j;
				}
				else if (answer[i][j]==maxi.siz)
					maxi.val=min(maxi.val,j);
			}
		cout<<maxi.val<<" "<<maxi.siz<<endl;
	}
}
