#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))
#define sf(x) scanf("%lld",&x);
#define sfc(x) scanf("%c",&c);

#define pf(x) printf("%lld",x);
#define pfc(c) printf("%c",x);

#define For(i,a,b) for(int i=a;i<b;i++)
#define Forr(i,a,b) for(int i=b;i>=a;i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pp;
typedef pair<pp,pp> ppi;
typedef vector<int> vv;
typedef vector<pp> vp;

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

vv v[10005];
int vis[10005]={0},tim=0,disc[10005]={0},low[10005]={0},par[10005]={0};
vp ans;

void dfs(int u)
{
	if(vis[u])
		return;
	
	vis[u]=1;
	low[u]=disc[u]=++tim;
	
	for(vv::iterator it=v[u].begin();it!=v[u].end();it++)
	{
		if(!vis[*it])
		{
			par[*it]=u;
			dfs(*it);
			low[u]=min(low[u],low[*it]);
			
			if(low[*it]>disc[u])
				ans.pb(mp(min(u,*it),max(u,*it)));		
		}
		else if(*it!=par[u])
			low[u]=min(low[u],disc[*it]); 		// if v is an ancestor store its dicovery time as a backedge			
	}	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d",&t);
	
	for(int t1=1;t1<=t;t1++)
	{
		tim=0;
		for(int i=0;i<10001;i++)
		{
			par[i]=-1,vis[i]=0,low[i]=0,disc[i]=0;
			v[i].clear();
		}
		ans.clear();
		
		int n,m;
		scanf("%d %d",&n,&m);
	
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			v[x].pb(y);v[y].pb(x);
		}
		
		for(int i=0;i<n;i++)
		{
			if(!vis[i])	
				dfs(i);
		}
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}	
	return 0;
}

