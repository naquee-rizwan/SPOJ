#include <bits/stdc++.h>
using namespace std;
int main() 
{
    float val;
    while(1)
   	{
     	cin>>val;
     	if (val==0)
     		break;
        float comp=0,i=1;
        for(i=1;comp<val;++i)
        	comp+=(1/(i+1));
        printf("%.0f card(s)\n",i-1);
    }
}
