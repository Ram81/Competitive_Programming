#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	return 0;
}














