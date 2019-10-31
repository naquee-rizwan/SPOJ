#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	while (1)
	{
		ll k;
		cin>>k;
		if (k==0)
			break;
		string str1,str2;
		cin>>str1>>str2;
		ll len1=str1.length(),len2=str2.length();
		ll mat[len1+1][len2+1];
		memset (mat,0,sizeof(mat));
		for (ll i=1;i<=len1;i++)
			for (ll j=1;j<=len2;j++)
				if (i>=k&&j>=k)
					if (str1[i-1]!=str2[j-1])
						mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
					else
					{
						ll cnt=1;
						mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
						while ((i-cnt)>=0&&(j-cnt)>=0&&str1[i-cnt]==str2[j-cnt])
						{
							if (cnt>=k)
								mat[i][j]=max(mat[i][j],mat[i-cnt][j-cnt]+cnt);
							cnt++;
						}
					}
		cout<<mat[len1][len2]<<endl;
	}
}
