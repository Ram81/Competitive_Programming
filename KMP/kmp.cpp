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

int lps[1100005]={0};
string a,b;

void buildLPS()
{
	memset(lps,0,sizeof(lps));
	int i1=1,i2=0,n=b.length();
	lps[0]=0;
	
	while(i1<n)
	{
		if(b[i1]==b[i2])
		{
			i2++;
			lps[i1]=i2;
			i1++;
		}
		else
		{
			if(i2==0)
				lps[i1]=0,i1++;
			else
				i2=lps[i2-1];
		}
	}
}

int KMP()
{
	int n1=a.length(),n2=b.length();
	int i1=0,i2=0,ans=0;
	
	buildLPS();
	
	while(i1<n1)
	{
		if(a[i1]==b[i2])
			i1++,i2++;
		
		if(i2==n2)
			i2=lps[i2-1],ans++;
		else if(i1<n1 && a[i1]!=b[i2])
		{
			if(i2!=0)
				i2=lps[i2-1];
			else
				i1++;
		}
	}
	return ans;
}

bool chk(string s1, string s2)
{
   int j = 0; 
   int n=s2.length(),m=s1.length();
   for (int i=0; i<n && j<m; i++)
       if (s1[j] == s2[i])
         j++;
 
   return (j==m);
}
 
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	a="aaaaaaa";
	b="aa";
	cout<<KMP()<<"\n";
	return 0;	
} 




