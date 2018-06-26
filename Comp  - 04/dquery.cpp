#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
ll seg[2000000],arr[2000000],pos[2000000],ans[2000000];
vector<pair<ll,ll> > vec[2000000];
void update(ll st,ll l,ll r,ll in,ll v)
{
	if(l==r)
	{
		seg[st]+=v;
		return;
	}
	ll mid=(l+r)/2;
	if(in<=mid)
	{
		update(st*2+1,l,mid,in,v);
	}
	else
	{
		update(st*2+2,mid+1,r,in,v);
	}
	seg[st]=seg[st*2+1]+seg[st*2+2];
}
ll query(ll st,ll l,ll r,ll ql,ll qr)
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
	return query(st*2+1,l,mid,ql,qr)+query(st*2+2,mid+1,r,ql,qr);
}
int main()
{
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		ll l,r;
		cin>>l>>r;
		l--;
		r--;
		vec[r].push_back(make_pair(l,i));
	}
	memset(pos,-1,sizeof(pos));
	for(int i=0;i<n;i++)
	{
		if(pos[arr[i]]!=-1)
		{
			update(0,0,n-1,pos[arr[i]],-1);
		}
		update(0,0,n-1,i,1);
		pos[arr[i]]=i;
		for(int j=0;j<vec[i].size();j++)
		{
			ans[vec[i][j].second]=query(0,0,n-1,vec[i][j].first,i);
		}
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<"\n";

	return 0;
}