#include<bits/stdc++.h>
using namespace std;
namespace _yz
{
	typedef long long ll;
	const ll N=100000+5,M=500000+5,inf=2147483647;
	struct edge{ll nxt,to,len;}e[M];
	ll n,m,Q,head[N],cnt=0,dis[N],vis[N];
	queue<ll>q;

	void add(ll a,ll b,ll len)
	{
		e[++cnt]=(edge){head[a],b,len};
		head[a]=cnt;
	}
	void spfa()
	{
		for(ll i=1;i<=n;i++) dis[i]=inf;
		dis[1]=0; vis[1]=1; q.push(1);
		while(!q.empty())
		{
			ll now=q.front(); q.pop();
			vis[now]=0;
			for(ll i=head[now];i;i=e[i].nxt)
			{
				ll len=e[i].len,to=e[i].to;
				if(dis[to]>(dis[now]^len))
				{
					dis[to]=(dis[now]^len);
					if(!vis[to]) q.push(to);
				}
			}
		}
	}
	void yzmain()
	{
		ll ta,tb,tl;
		scanf("%lld%lld%lld",&n,&m,&Q);
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&ta,&tb,&tl);
			add(ta,tb,tl);
			add(tb,ta,tl);
		}
		spfa();
		for(ll i=1;i<=Q;i++)
		{
			scanf("%lld%lld",&ta,&tb);
			printf("%lld\n",(dis[ta]^dis[tb]));
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