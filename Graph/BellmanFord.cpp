#include <bits/stdc++.h>
#include<stack>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef pair<pp,ll> ppi;
typedef vector<int> vv;
typedef vector<ppi> vp;
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

vp v;
int vis[205]={0};
ll dist[205];

void bellmanFord(int src,int n,int m)
{
	for(int i=1;i<=n;i++)
		dist[i]=LINF;
	dist[src]=0;
	
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int s=v[j].first.first;
			int d=v[j].first.second;
			ll c=v[j].second;
			if(dist[s]!=LINF && dist[d]>(c+dist[s]))
				dist[d]=c+dist[s];			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	
	for(int t1=1;t1<=t;t1++)
	{
		v.clear();
		memset(vis,0,sizeof(vis));
		
		int n,m;
		cin>>n;
		
		ll a[202]={0};
		for(int i=0;i<n;i++)
			cin>>a[i+1];
		
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int x,y,w;
			cin>>x>>y>>w;
			v.pb(mp(mp(x,y),w));
		}
		
		bellmanFord(1,n,m);
		
		
	}	
	return 0;
}

