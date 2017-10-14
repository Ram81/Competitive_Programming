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

int lps[100005];

void LPS(string str)
{
	ll p1=1,p2=0;
	lps[0] = 0;	
	ll n = str.length();
	
	while(p1<n)
	{
		if(str[p1]==str[p2])
		{
			lps[p1] = lps[p1-1]+1;
			p1+=1;
			p2+=1;
		}
		else
		{
			if(p2==0)
			{
				lps[p1] = 0;
				p1+=1;
			}
			else
			{
				p2 = lps[p2-1];
			}
		}
	}
}

void KMP(string str,string pat)
{
	ll n1 = str.length();
	ll n2 = pat.length();

	LPS(pat);

	ll p1=0,p2=0;	

	while(p1<n1)
	{
		if(str[p1]==pat[p2])
			p1+=1,p2+=1;

		if(p2==n2)
			p2 = lps[p2-1],cout<<"Pattern found "<<p1-p2<<endl;

		else if(p1<n1 && str[p1]!=pat[p2])
		{
			if(p2!=0)
				p2 =  lps[p2-1];
			else
				p1+=1;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	string a = "ABABABCABABABCABABABC";
	string b = "ABABA";
	KMP(a,b);
} 
