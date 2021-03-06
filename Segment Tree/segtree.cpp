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

#define For(i,a,b) for(int i=a;i<b;i++)
#define Forr(i,a,b) for(int i=b-1;i>=a;i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pp;
typedef pair<pp,int> ppi;
typedef vector<int> vv;
typedef map<pp,int> mpp;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll fpow_nomod(ll n, ll k) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n; n = n * n;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

ll st[400005];
ll a[100005];

ll build(int s,int e,int i)
{
	if(s==e)
		return(st[i]=a[s]);

	int mid=(s+e)/2;
	st[i]=build(s,mid,2*i+1)+build(mid+1,e,2*i+2);
	return st[i];
}

ll query(int s, int e,int l,int r,int i)
{
	if(l<=s && r>=e)
		return st[i];
	if(e<l || s>r)
		return 0;
	int mid=(s+e)/2;
	return(query(s,mid,l,r,2*i+1)+query(mid+1,e,l,r,2*i+2));
}

void update(int s,int e,int val,int idx,int i)
{
	if(s==e)
		a[idx]+=val,st[i]+=val;
	else
	{
		int mid=(s+e)/2;
		if(s<=idx && idx<=mid)
			update(s,mid,val,idx,2*i+1);
		else
			update(mid+1,e,val,idx,2*i+2);
		st[i]=st[2*i+1]+st[2*i+2];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	return 0;
}
