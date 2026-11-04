#include<bits/stdc++.h>
using namespace std;
namespace _yz
{
	typedef long long ll;
	const ll N=10000+5;
	ll n,m,dad[N];

	ll find(ll x)
	{
		while(x!=dad[x])
			x=dad[x]=dad[dad[x]];
		return x;
	}
	void merge(ll a,ll b)
	{
		a=find(a); b=find(b);
		dad[a]=b;
	}
	ll check(ll a,ll b)
	{
		a=find(a); b=find(b);
		if(dad[a]==dad[b]) return 1;
		return 0;
	}
	void yzmain()
	{
		ll op,ta,tb;
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++) dad[i]=i;
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&op,&ta,&tb);
			if(op==1) merge(ta,tb);
			else
			{
				if(check(ta,tb)) printf("Y\n");
				else printf("N\n");
			}
		}
		return;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	_yz::yzmain();
	return 0;
}