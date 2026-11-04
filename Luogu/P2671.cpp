#include<bits/stdc++.h>
using namespace std;
namespace _yz
{
	typedef long long ll;
	const ll N=100000+10,mod=10007;
	ll n,m,col[N],num[N],out=0;
	struct ans{ll slf,nx,n,ans,cnt;} ans[N][2];
	void yzmain()
	{
		memset(ans,0,sizeof(ans));
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++)
			scanf("%lld",num+i);
		for(ll i=1;i<=n;i++)
			scanf("%lld",col+i);
		for(ll i=1;i<=n;i++)
		{
			if(i%2)
			{
				ans[col[i]][1].ans+=i*num[i]*ans[col[i]][1].cnt%mod;
				ans[col[i]][1].ans+=ans[col[i]][1].nx*i%mod+ans[col[i]][1].n*num[i]%mod+ans[col[i]][1].slf;
				ans[col[i]][1].nx+=num[i]%mod;
				ans[col[i]][1].n+=i%mod;
				ans[col[i]][1].slf+=i*num[i]%mod;
				ans[col[i]][1].ans%=mod;
				ans[col[i]][1].nx%=mod;
				ans[col[i]][1].n%=mod;
				ans[col[i]][1].slf%=mod;
				ans[col[i]][1].cnt+=1;
			}
			else
			{
				ans[col[i]][0].ans+=i*num[i]*ans[col[i]][0].cnt%mod;
				ans[col[i]][0].ans+=ans[col[i]][0].nx*i%mod+ans[col[i]][0].n*num[i]%mod+ans[col[i]][0].slf;
				ans[col[i]][0].nx+=num[i]%mod;
				ans[col[i]][0].n+=i%mod;
				ans[col[i]][0].slf+=i*num[i]%mod;
				ans[col[i]][0].ans%=mod;
				ans[col[i]][0].nx%=mod;
				ans[col[i]][0].n%=mod;
				ans[col[i]][0].slf%=mod;
				ans[col[i]][0].cnt+=1;
			}
		}
		for(ll i=1;i<=m;i++)
		{
			out+=ans[i][0].ans;
			out+=ans[i][1].ans;
			out%=mod;
		}
		printf("%lld\n",out);
		return;
	}
}
int main()
{
	_yz::yzmain();
	return 0;
}
/*
4 1
1 1 1 1
1 1 1 1
8+12

3 1
1 1 1
1 1 1
*/