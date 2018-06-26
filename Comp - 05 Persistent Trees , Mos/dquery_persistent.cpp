//dquery
#include<bits/stdc++.h>
using namespace std;
#define ll int
ll arr[300002],pre[2000001],seg[50000000],newindex=0,L[50000000],R[50000000],root[300002],coun[300002];

void build(ll id,ll l,ll r)
{

	if(l==r)
	{
		
		return;
	}
	ll mid=(l+r)/2;
	L[id]=newindex++;
	R[id]=newindex++;
	build(L[id],l,mid);
	build(R[id],mid+1,r);
}
ll update(ll st,ll in,ll u,ll l,ll r)
{
	
	ll id=newindex++;
	if(l==r)
	{
		seg[id]=coun[l]+=u;
		return id;
	}
	L[id]=L[st];
	R[id]=R[st];
	ll mid=(l+r)/2;
	if(in<=mid)
	{
		L[id]=update(L[id],in,u,l,mid);
		seg[id]=seg[L[id]]+seg[R[id]];
	}
	else
	{
		R[id]=update(R[id],in,u,mid+1,r);
		seg[id]=seg[L[id]]+seg[R[id]];	
	}
	return id;
}
ll query(ll st,ll ql,ll qr,ll l,ll r)
{
	if(l>qr||r<ql)
	{
		return 0;
	}
	if(l>=ql&&r<=qr)
	{
		return seg[st];
	}
	ll mid=(l+r)/2;
	return query(L[st],ql,qr,l,mid)+query(R[st],ql,qr,mid+1,r);
}
int main()
{
	ll n,q;
	scanf("%d",&n);
	memset(pre,-1,sizeof(pre));
	build(0,0,n-1);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		ll temp=0;
		if(i>0)
			temp=root[i-1];
		if(pre[arr[i]]!=-1)
		{
			temp=update(temp,pre[arr[i]],-1,0,n-1);
		}
		root[i]=update(temp,i,1,0,n-1);
		
		
		pre[arr[i]]=i;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		ll l,r;
		scanf("%d%d",&l,&r);
		l--;
		r--;
		printf("%d\n",query(root[r],l,r,0,n-1));	
	}
}