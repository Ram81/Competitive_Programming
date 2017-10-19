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

typedef struct Suffix{
	int idx,rank[2];
}Suffix;

typedef vector<Suffix> vi;

int cmp(const Suffix &a,const Suffix &b)
{
	return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]?1:0):(a.rank[0]<b.rank[0]?1:0);
}

vv buildSuffix(string s)
{
	int n=s.length();
	vi suff(n);
	
	for(int i=0;i<n;i++)
	{
		suff[i].idx=i;
		suff[i].rank[0]=s[i]-'a';
		suff[i].rank[1]=(i+1)<n?(s[i+1]-'a'):-1;
	}
	
	sort(suff.begin(),suff.end(),cmp);
	
	int index[n];
	vv v(n);
	for(int k=4;k<2*n;k*=2)
	{
		int curRank=0;
		int prevRank=suff[0].rank[0];
		suff[0].rank[0]=curRank;
		index[suff[0].idx]=0;
		
		for(int i=1;i<n;i++)
		{
			if(suff[i].rank[0]==prevRank && suff[i].rank[1]==suff[i-1].rank[1])
			{
				prevRank=suff[i].rank[0];
				suff[i].rank[0]=curRank;
			}
			else
			{
				prevRank=suff[i].rank[0];
				suff[i].rank[0]=++curRank;
			}
			index[suff[i].idx]=i;
		}
		
		for(int i=0;i<n;i++)
		{
			int nxtIdx=suff[i].idx+k/2;
			suff[i].rank[1]=(nxtIdx<n)?suff[index[nxtIdx]].rank[0]:-1;
		}
		sort(suff.begin(),suff.end(),cmp);
	}
	
	for(int i=0;i<n;i++)
		v[i]=suff[i].idx;
	return v;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	buildSuffix("banana");
	return 0;
}
