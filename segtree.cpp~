#include<bits/stdc++.h>
using namespace std;

ll st[400005];
ll a[100005];
ll lazy[400005];


ll build(int s,int e,int i)
{
	if(s==e)
		return(st[i]=a[s]);

	int mid=(s+e)/2;
	st[i]=build(s,mid,2*i+1)+build(mid+1,e,2*i+2);
	return st[i];
}

ll getSum(int s, int e,int l,int r,int i)
{
	if(l<=s && r>=e)
		return st[i];
	if(e<l || s>r)
		return 0;
	int mid=(s+e)/2;
	return(getSum(s,mid,l,r,2*i+1)+getSum(mid+1,e,l,r,2*i+2));
}

void update(int s,int e,int val,int idx,int i)
{
	if(idx<s || idx>e)
		return;

	st[i]=st[i]+val;
	if(s!=e)
	{
		int mid=(s+e)/2;
		update(s,mid,val,idx,2*i+1);
		update(mid+1,e,val,idx,2*i+2);
	}
}

void lazyUpdate(int s,int e,int l,int r,int i,int val)
{
	if(lazy[i]!=0)	
	{
		st[i]+=(e-s+1)*lazy[i];
		if(s!=e)
		{
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(s>e || s>r || e<l)
		return;
	

	if(s>=l && e<=r)
	{
		st[i]+=(e-s+1)*val;
		if(s!=e)
		{
			lazy[2*i+1]+=val;
			lazy[2*i+2]+=val;
		}
		return;
	}
	int mid=(s+e)/2;
	lazyUpdate(s,mid,l,r,2*i+1,val);
	lazyUpdate(mid+1,e,l,r,2*i+2,val);

	st[i]=st[2*i+1]+st[2*i+2];
}















