#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
map <ll,ll> m;
ll solve(ll n)
{
    if (n==0)
        return 0;
    if (m.find(n)==m.end())
        m[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
    return m[n];
}
int main()
{
    ll n;
    while (cin>>n)
        cout<<solve(n)<<endl;
}
