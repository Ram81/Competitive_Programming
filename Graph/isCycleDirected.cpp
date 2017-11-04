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
typedef vector<pp> vp;
typedef map<string,int> mpp;

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
mpp m1;

int dfs(int u,int vis[100005],int rec[100005])
{
	if(!vis[u])
	{
		vis[u]=1;
		rec[u]=1;
		for(vv::iterator it=v[u].begin();it!=v[u].end();it++)
		{
			if(!vis[*it] && dfs(*it,vis,rec))
				return 1;
			else if(rec[*it])
				return 1;
		}
	}
	rec[u]=0;
	return 0;	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	
	for(int t1=1;t1<=t;t1++)
	{
		int f=0;
		for(int i=0;i<100001;i++)
			v[i].clear();
		m1.clear();
		int vis[100005]={0},rec[100005]={0};
		
		int n,m,cnt=1;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
		}
		
		for(int i=1;i<=cnt && f==0;i++)
		{
			if(!vis[i])	
				f=dfs(i,vis,rec);
		}
		if(!f)
			printf("Case %d: Yes\n",t1);
		else
			printf("Case %d: No\n",t1);
	}	
	return 0;
}

