#include <bits/stdc++.h>
using namespace std;
#define N 50010
int i,j,k,n,m,x,y,t,f[N],a,p,mark[N],tim[N],s[N],num,ti;
struct data{int x,y,z,id1,id2,z1;}q[N];
int mi(int x,int y){if (y==0)return 1;int t=mi(x,y>>1);t=1ll*t*t%p;return y&1?(1ll*x*t%p):t;}
bool cmp1(const data&a,const data&b){return a.x==b.x?a.id2>b.id2:a.x<b.x;}
bool cmp2(const data&a,const data&b){return a.y==b.y?a.id2>b.id2:a.y<b.y;}
bool cmp3(const data&a,const data&b){return a.z<b.z;}
int query(int x){int t=0;while (x){if (tim[x]!=ti){tim[x]=ti;s[x]=0;}t=max(t,s[x]);x-=x&-x;}return t;}
void insert(int x,int y){while (x<=n){if (tim[x]!=ti){tim[x]=ti;s[x]=0;}s[x]=max(s[x],y);x+=x&-x;}}
void cdq(int l,int r){
	if (l==r)return ;
	int mid=l+r>>1;
	int mx=q[mid].x;
	cdq(l,mid);
	sort(q+l,q+1+r,cmp2);
	ti++;
	for (int i=l;i<=r;i++){
		if (q[i].id2>mid){
			f[q[i].id1]=max(f[q[i].id1],query(q[i].z));
		}
		else {
			insert(q[i].z+1,f[q[i].id1]+1);
		}
	}
//	printf("$$$\n");
//	for (int i=l;i<=r;i++)printf("%d %d %d %d %d\n",q[i].x,q[i].y,q[i].z,f[q[i].id1],q[i].id2);
	sort(q+l,q+1+r,cmp1);
	cdq(mid+1,r);
}
int main(){
	scanf("%d%d%d",&a,&p,&n);
	for (i=1;i<=n;i++){
		q[i]={mi(a,3*i-2),mi(a,3*i-1),mi(a,3*i),i,0,0};
		if (q[i].y<q[i].z)swap(q[i].y,q[i].z);
		if (q[i].x<q[i].y)swap(q[i].x,q[i].y);
		if (q[i].y<q[i].z)swap(q[i].y,q[i].z);
	}
	sort(q+1,q+1+n,cmp3);
	for (i=1;i<=n;i++)q[i].z1=(q[i].z!=q[i-1].z)?++num:num;
	for (i=1;i<=n;i++)q[i].z=q[i].z1;
	sort(q+1,q+1+n,cmp1);
//	printf("---\n");
//	for (i=1;i<=n;i++)printf("%d %d %d\n",q[i].x,q[i].y,q[i].z);
	for (i=1;i<=n;i++)q[i].id2=i;
	cdq(1,n);
	int ans=0;for (i=1;i<=n;i++)ans=max(ans,f[i]);
//	for (i=1;i<=n;i++)printf("%d ",f[i]);printf("\n");
	printf("%d\n",ans+1);
	return 0;
}
