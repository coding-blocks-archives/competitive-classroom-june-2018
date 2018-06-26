#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[2000000],root[2000000],L[2000000],R[2000000],seg[2000000],newindex;
vector<pair<ll,ll> > vec;
void build(ll l,ll r,ll id)
{
	
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)/2;
	L[id]=newindex++;
	R[id]=newindex++;
	build(l,mid,L[id]);
	build(mid+1,r,R[id]);
}
ll update(ll st,ll l,ll r,ll in)
{
	ll id=newindex++;
	
		if(l==r)
		{
			seg[id]=seg[st]+1;
			return id;
		}
		L[id]=L[st];
		R[id]=R[st];
		ll mid=(l+r)/2;
		if(in<=mid)
		{
			L[id]=update(L[st],l,mid,in);
		}
		else
		{
			R[id]=update(R[st],mid+1,r,in);
		}
		seg[id]=seg[L[id]]+seg[R[id]];
		return id;
	
}
ll query(ll l,ll r,ll rid,ll lid,ll k)
{
	if(l==r)
	{
		return vec[l].first;
	}
	ll lcount=seg[L[rid]]-seg[L[lid]];
	ll mid=(l+r)/2;
	if(lcount<k)
	{
		return query(mid+1,r,R[rid],R[lid],k-lcount);
	}
	else
	{
		return query(l,mid,L[rid],L[lid],k);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	ll n,q;
	cin>>n>>q;
	build(0,n-1,0);
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		//arr[i]=a;
		vec.push_back(make_pair(a,i));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++)
	{
		arr[vec[i].second]=i;
	}
	for(int i=0;i<n;i++)
	{
		
		if(i>0)
		root[i]=update(root[i-1],0,n-1,arr[i]);
		else
		root[i]=update(0,0,n-1,arr[i]);
	}
	for(int i=0;i<q;i++)
	{
		ll l,r,k;
		cin>>l>>r>>k;
		l--;
		r--;
		if(l>0)
		cout<<query(0,n-1,root[r],root[l-1],k)<<"\n";
		else
		cout<<query(0,n-1,root[r],0,k)<<"\n";
		
	}
}