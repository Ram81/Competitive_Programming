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

ll bit[100005]={0};

void update(int n,int i,int val)
{
	i++;
	while(i<=n)
		bit[i]+=val,i+=(i & (-i));
}

ll query(int n,int i)
{
	i++;
	ll ans=0;
	while(i>0)
		ans+=bit[i],i-=(i & (-i));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}

