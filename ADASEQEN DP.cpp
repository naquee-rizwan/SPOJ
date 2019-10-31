#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n,m;
	cin>>n>>m;
	ll arr[26];
	for (ll i=0;i<26;i++)
		cin>>arr[i];
	string str1,str2;
	cin>>str1;
	cin>>str2;
	ll len1=str1.length(),len2=str2.length(),mat[len1+1][len2+1];
	for (ll i=0;i<=len1;i++)
		mat[i][0]=0;
	for (ll i=0;i<=len2;i++)
		mat[0][i]=0;
	for (ll i=1;i<=len1;i++)
		for (ll j=1;j<=len2;j++)
			if (str1[i-1]==str2[j-1])
			{
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
				mat[i][j]=max(mat[i-1][j-1]+arr[str1[i-1]-'a'],mat[i][j]);
			}
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
	cout<<mat[len1][len2];
}
