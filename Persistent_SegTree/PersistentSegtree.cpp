#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define pp pair<ll,ll>
#define inf 1e9
using namespace std;
 
const int N=100005,size=6000005;
//l-left child,r-right child,st-value,node-global node id
int st[size],l[size],r[size],node,k;           
 
int root[N];
 
int newleaf(int value)
{
    int p=node;node++;
    st[p]=value;
    l[p]=-1;r[p]=-1;
    
    return p;
}
 
int newparent(int lf,int rg)
{
    int p=node;node++;
    st[p]=st[lf]+st[rg];
    l[p]=lf;
    r[p]=rg;
    
    return p;
}
 
int build(int s,int e)
{
    if(s==e)
    return newleaf(0);
    
    int mid=(s+e)/2;
    return newparent(build(s,mid),build(mid+1,e));
}
 
int update(int s,int e,int x,int p,int val)
{
    if(s==e)
    return newleaf(val);
    
    int mid=(s+e)/2;
    if(x<=mid)
    return newparent(update(s,mid,x,l[p],val),r[p]);
    
    return newparent(l[p],update(mid+1,e,x,r[p],val));
}
 
int query(int a,int b,int s,int e,int k)
{
   if(s==e)
   return s;
   
   int mid=(s+e)/2;
   int c=st[l[b]]-st[l[a]];
   if(c<k)
        return query(r[a],r[b],mid+1,e,k-c);
   return query(l[a],l[b],s,mid,k);
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    int arr[N],R[N]; map<int,int> mp; 
  
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]=0;
    }
   
    int maxi=0;
    for(map<int,int>:: iterator it=mp.begin();it!=mp.end();it++)
    {
        mp[it->first]=maxi;
        R[maxi]=it->first;
        maxi++;
    }
    
   
    int null=build(0,n-1);
    
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        root[i]=update(0,n-1,mp[arr[i]],root[i-1],1);
        else
        root[i]=update(0,n-1,mp[arr[i]],null,1);
    }
  
 
    
    while(m--)
    {
        int i,j;
        cin>>i>>j>>k;
        i--;j--;
        if(i-1>=0)
        cout<<R[query(root[i-1],root[j],0,n-1,k)]<<"\n";
        else
        cout<<R[query(null,root[j],0,n-1,k)]<<"\n";
    }
    
    return 0;
}  
