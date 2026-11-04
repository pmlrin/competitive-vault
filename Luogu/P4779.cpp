#include<bits/stdc++.h>
using namespace std;
namespace _yz
{
	typedef long long ll;
	const ll N=100000+5,M=500000+5,inf=2147483647;
	struct edge{ll nxt,to,len;}e[M];
	struct node{ll p,dis;};
	ll n,m,s,head[N],cnt=0,dis[N],vis[N];
	priority_queue<node>q;

	bool operator<(node a,node b){return a.dis>b.dis;}
	void add(ll a,ll b,ll len)
	{
		e[++cnt]=(edge){head[a],b,len};
		head[a]=cnt;
	}
	void dij()
	{
		for(ll i=1;i<=n;i++) dis[i]=inf;
		dis[s]=0; q.push((node){s,0});
		while(!q.empty())
		{
			node now=q.top(); q.pop();
			if(vis[now.p]) continue;
			vis[now.p]=1;
			for(ll i=head[now.p];i;i=e[i].nxt)
			{
				ll len=e[i].len,to=e[i].to;
				if(dis[to]>dis[now.p]+len)
				{
					dis[to]=dis[now.p]+len;
					q.push((node){to,dis[to]});
				}
			}
		}
	}
	void yzmain()
	{
		ll ta,tb,tl;
		scanf("%lld%lld%lld",&n,&m,&s);
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&ta,&tb,&tl);
			add(ta,tb,tl);
		}
		dij();
		for(ll i=1;i<=n;i++) printf("%lld ",dis[i]);
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