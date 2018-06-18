#include<iostream>
using namespace std;

float squareRoot(int n,int p){

	int s = 0;
	int e = n;

	float ans = 0;
	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid==n){
			return mid;
		}
		if(mid*mid<n){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}

	float inc = 0.1;
	for(int place=0;place<p;place++){

		while(ans*ans <=n){
			ans += inc;
		}
		ans = ans - inc;
		inc = inc/10;
	}

	return ans;
}

int main(){

	int n;
	cin>>n;
	int p;
	cin>>p;

	cout<<squareRoot(n,p)<<endl;

	return 0;
}