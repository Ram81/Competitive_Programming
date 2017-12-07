#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))

#define sf(x) scanf("%d",&x)
#define sfll(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&c)

#define pf(x) printf("%d",x)
#define pfll(x) printf("%lld",x)
#define pfc(c) printf("%c",x)
#define pfl() printf("\n")

#define For(i,a,b) for(int i=a;i<b;i++)
#define Forr(i,a,b) for(int i=(b)-1;i>=(a);i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pp;
typedef pair<pp,int> ppi;
typedef vector<ll> vv;
typedef map<pp,int> mpp;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll fpow_nomod(ll n, ll k) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n; n = n * n;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

ll n,m;
ll lim = 255;
ll x = 20*lim,y=9;
vv a[4000001];
vv memo[4000001];
vv pre(4000001);
vv lmax(4000001),rmax(4000001);
vv suf(4000001);

void foo(int i,int l,int r,int lb,int ub)
{	
    if(lb>ub || lb>=m || ub<0 || lb<0 || ub>=m)
        return;
    
	int j=(lb+ub)/2;	
	int bestk=l;
	
	for(int k=l;k<=r;k++)
	{
		if(j<k)
		{
			ll x=0;
			if(j<k-1)
				x=pre[k-1]-pre[j];

			ll ans=memo[i-1][k]+rmax[k]+lmax[j]+x;

			if(memo[i][j]<=ans)
				memo[i][j]=ans,bestk=k;
		}
		else if(k<j)
		{
			ll x=0;
			if(k<j-1)
				x=pre[j-1]-pre[k];
			ll ans=memo[i-1][k]+lmax[k]+rmax[j]+x;
			
			if(memo[i][j]<=ans)
				memo[i][j]=ans,bestk=k;
		}
		else
		{
			ll ans=memo[i-1][k]+lmax[j]+rmax[j]-a[i][j];
			
			if(memo[i][j]<=ans)
				memo[i][j]=ans,bestk=k;
		}
	}
	
	if(lb<=j-1)	
		foo(i,l,bestk,lb,j-1);
	if(j+1<=ub)
		foo(i,bestk,r,j+1,ub);
	
}
void init()
{
        For(j,0,m)
            pre[j]=0,suf[j]=0,lmax[j]=0,rmax[j]=0;
}
void Foo()
{
	
	For(i,1,n+1)
	{
        init();
        
		pre[0]=a[i][0];
		
		suf[m-1]=a[i][m-1];
		
		rmax[0]=lmax[0]=-1*LINF;
		For(k,1,m)			
			pre[k]=pre[k-1]+a[i][k],lmax[k]=-1*LINF,rmax[k]=-1*LINF;       
		
		Forr(k,0,m-1)
			suf[k]=suf[k+1]+a[i][k];

		ll a1=-1*LINF;
		
		For(j,0,m)
		{
			a1=max(a1,suf[j]);
			lmax[j]=a1;
			if(j+1<m)
				lmax[j]-=suf[j+1];		
		}
		
		a1=-1*LINF;
		
		Forr(j,0,m)
		{
			a1=max(a1,pre[j]);
			rmax[j]=a1;
			if(j-1>=0)
				rmax[j]-=pre[j-1];
		}
		foo(i,0,m-1,0,m-1);
	}
}

int main() {
	sfll(n);sfll(m);
	
    For(i,0,m)
        memo[0].pb(0);
    
    
    For(i,1,n+1)
    {
		For(j,0,m)
        {
            ll x;
			sfll(x);
            a[i].pb(x);
            memo[i].pb(-1*LINF);
        }
    }
	
	Foo();
	
	ll res=-1*LINF;
	For(i,0,m)
		res=max(res,memo[n][i]);
	pfll(res);
		
	return 0;
}

