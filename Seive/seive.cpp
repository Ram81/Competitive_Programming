#include<bits/stdc++.h>
using namespace std;

int seive[100005]={0};

void seive_()
{
	seive[1]=0,seive[0]=0;
	for(int i=2;i<100005;i++)
	{
		if(!seive[i])
			for(int j=2*i;j<100005;j+=i)
				seive[j]=1;
	}
}

int main()
{
	seive_();
	for(int i=0;i<20;i++)
		printf("%d ",seive[i]);
	return 0;
}