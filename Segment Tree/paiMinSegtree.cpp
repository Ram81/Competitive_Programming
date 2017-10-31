#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))
#define sf(x) scanf("%lld",&x);
#define sfc(x) scanf("%c",&c);

#define pf(x) printf("%lld",x);
#define pfc(c) printf("%c",x);

#define for(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i=b;i>=a;i--)

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef pair<pp,pp> ppi;
typedef vector<pp> vv;

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

vv st(400005);
ll a[400005];

void build(int s,int e,int i)
{
	if(s==e)
	{
		st[i].first=a[s];
		st[i].second=s;
		return;
	}

	int mid=(s+e)/2;
	build(s,mid,2*i+1);
	build(mid+1,e,2*i+2);
	
	st[i]=(st[2*i+1].first<=st[2*i+2].first)?st[2*i+1]:st[2*i+2];
}

pp query(int s, int e,int l,int r,int i)
{
	if(l<=s && r>=e)
		return st[i];
	if(e<l || s>r)
		return mp(LINF,LINF);
		
	int mid=(s+e)/2;
	pp p1=query(s,mid,l,r,2*i+1);
	pp p2=query(mid+1,e,l,r,2*i+2);
	
	return ((p1.first<=p2.first)?p1:p2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	return 0;
}
