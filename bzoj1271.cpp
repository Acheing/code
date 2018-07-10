#include <bits/stdc++.h>
using namespace std;
#define N 200010
typedef unsigned long long ll;
int i,j,k,n,m,x,y,t,T;
struct data{ll x,y,t;}a[N];
long long num;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){f=ch=='-'?-f:f;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
ll check(ll x){
	ll p=0;
	for (int i=1;i<=n;i++)
		if (a[i].x<=x){
			ll delta=(min(x,a[i].y)-a[i].x)/a[i].t+1;
			p+=delta;
		}
	return p;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&t);
			a[i]={x,y,t};
		}
		ll l=0,r=1ll<<31,ans=-1;
		while (l<=r){
			ll mid=l+r>>1;
			if (check(mid)&1)ans=mid,r=mid-1;else l=mid+1;
		}
		if (ans==-1)printf("Poor QIN Teng:(\n");else printf("%lld %lld\n",ans,check(ans)-check(ans-1));
//		printf("#%lld\n",check(6573));
	}
	return 0;
}
