#include<iostream>
using namespace std;

int fastPower(int a,int b){
	//Base Case
	if(b==0){
		return 1;
	}
	//Rec Case
	int smallAns = fastPower(a,b/2);
	smallAns *= smallAns;

	if(b&1){
		return a*smallAns;
	}
	return smallAns;
}

//Bitmasking Iterative Approach
int fastPowerIterative(int a,int n){

	int res=1;
	while(n){
		if(n&1){
			res = res*a;
		}
		n = n>>1;
		a *= a;
	}
	return res;

}
int main(){
	int a=5,b=3;
	cout<<fastPowerIterative(a,b)<<endl;

}