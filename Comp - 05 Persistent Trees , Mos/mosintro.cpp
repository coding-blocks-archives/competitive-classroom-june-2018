#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll,pair<ll,ll> > p1,pair<ll,pair<ll,ll> > p2)
{
	if(p1.first/bucket!=p2.first/bucket)
		return p1.first/bucket<p2.first/bucket;
	return p1.second.first<p2.second.first;
}
void add(ll i)
{
	sum+=arr[i];
}
void remove(ll i)
{
	sum-=arr[i];
}
int main()
{
	ll n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<q;i++)
	{
		ll l,r;
		cin>>l>>r;
		vec.push_back(make_pair(l,make_pair(r,i)));
	}
	sort(vec.begin(),vec.end(),cmp);
	ll l=0,r=-1;
	for(int i=0;i<vec.size();i++)
	{
		while(r<vec[i].second.first)
		{
			r++;
			add(r);
		}
		while(r>vec[i].second.first)
		{
			remove(r);
			r--;
		}
		while(l<vec[i].first)
		{
			
			remove(l);
			l++;
		}
		while(l>vec[i].first)
		{
			l--;
			add(l);
		}
			
	}
}