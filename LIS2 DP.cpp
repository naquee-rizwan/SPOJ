#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll binary_search(ll arr[],ll left,ll right,ll find)
{
    if (arr[right]<find)
        return -1;
    if (arr[left]>=find)
        return left;
    ll mid=left+(right-left)/2;
    if (arr[mid]==find)
        return mid;
    else if (arr[mid]>find)
        if (mid-1>=left&&arr[mid-1]<find)
            return mid;
        else
            return binary_search(arr,left,mid-1,find);
    else
        if (mid+1<=right&&arr[mid+1]>=find)
            return mid+1;
        else
            return binary_search(arr,mid+1,right,find);
}
int main()
{
    ll n;
	cin>>n;
	ll a1i[n+1],a2i[n+1],a2[n+1],a3[n+1],lis=0;
	for (ll i=1;i<=n;i++)
		cin>>a1i[i]>>a2i[i];
    a2[0]=-1000000000000000000;
    a3[0]=-1000000000000000000;
    for (ll i=1;i<=n;i++)
    {
        a2[i]=1000000000000000000;
        a3[i]=1000000000000000000;
    }
    for (ll i=1;i<=n;i++)
    {
        ll j=binary_search(a2,0,n,a1i[i]);
		while (j-1>=1&&a2[j-1]==a2[j])
			j--;
		ll k=binary_search(a3,0,j,a2i[i]);
		while (k-1>=1&&a2[k-1]==a2[k])
			k--;
        lis=max(lis,k);
        a2[k]=a1i[i];
        a3[k]=a2i[i];
    }
    cout<<lis<<endl;
}
