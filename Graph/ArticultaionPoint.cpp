#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))
#define sf(x) scanf("%lld",&x)
#define sfc(x) scanf("%c",&c)

#define pf(x) printf("%lld",x)
#define pfc(c) printf("%c",x)

#define For(i,a,b) for(int i=a;i<b;i++)
#define Forr(i,a,b) for(int i=b;i>=a;i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pp;
typedef pair<pp,pp> ppi;
typedef vector<int> vv;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

vv v[100005];
int vis[100005]={0},tim=0,disc[100005]={0},low[100005]={0},par[100005]={0};
int f[100005]={0};

void dfs(int u)
{
	int c=0;
	if(vis[u])
		return;
	
	vis[u]=1;
	low[u]=disc[u]=++tim;
	
	for(vv::iterator it=v[u].begin();it!=v[u].end();it++)
	{
		if(!vis[*it])
		{
			c++;
			par[*it]=u;
			dfs(*it);
			low[u]=min(low[u],low[*it]);
			if(par[u]==-1 && c>1)
				f[u]=1;
			if(par[u]!=-1 && low[*it]>=disc[u])	// check for a backedge if u is not a root
				f[u]=1;				
		}
		else if(*it!=par[u])
			low[u]=min(low[u],disc[*it]); 		// if v is an ancestor store its dicovery time as a backedge			
	}	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=0;i<100001;i++)
		par[i]=-1,f[i]=0,vis[i]=0,low[i]=0,disc[i]=0;
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		v[x].pb(y);v[y].pb(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(f[i])
			cout<<i<<" ";
	}
	return 0;
}

