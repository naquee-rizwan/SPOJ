#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int turns,dp[4];
string rec[101][10][10][10][10],number;
string recursion(int step,string number)
{
	if (step>turns)
		return number;
	for (int i=0;i<4;i++)
		dp[i]=number[i]-'0';
	string &temp=rec[step][dp[0]][dp[1]][dp[2]][dp[3]];
	if (temp!="-1")
		return temp;
	if (step&1)
		temp="0000";
	else
		temp="9999";
	for (int i=0;i<4;i++)
	{
		string temp2=number;
		temp2[i]=(temp2[i]-'0'+1)%10+'0';
		if (step&1)
			temp=max(recursion(step+1,temp2),temp);
		else
			temp=min(recursion(step+1,temp2),temp);
	}
	return temp;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>number>>turns;
		for (ll i=1;i<=turns;i++)
			for (ll fd=0;fd<10;fd++)
				for (ll sd=0;sd<10;sd++)
					for (ll td=0;td<10;td++)
						for (ll fr=0;fr<10;fr++)
							rec[i][fd][sd][td][fr]="-1";
		if (recursion(1,number)>number)
			cout<<"Ada\n";
		else
			cout<<"Vinit\n";
	}
}
