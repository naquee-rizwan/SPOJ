#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		ll len1=str1.length(),len2=str2.length();
		ll mat[len1+1][len2+1];
		for (ll i=0;i<=len1;i++)
			mat[i][0]=i;
		for (ll j=0;j<=len2;j++)
			mat[0][j]=j;
		for (ll i=1;i<=len1;i++)
		{
			for (ll j=1;j<=len2;j++)
			{
				if (str1[i-1]==str2[j-1])
					mat[i][j]=mat[i-1][j-1];
				else
					mat[i][j]=min(mat[i-1][j-1],min(mat[i][j-1],mat[i-1][j]))+1;
			}
		}
		cout<<mat[len1][len2]<<endl;
	}
}
