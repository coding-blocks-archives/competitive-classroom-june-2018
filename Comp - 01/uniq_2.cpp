#include<iostream>
using namespace std;


int main(){

	int a[] = {7,2,3,5,8,5,2,7};
	int n = sizeof(a)/sizeof(int);
	int res = 0;
	
	//First step - find xor of all
	for(int i=0;i<n;i++){
		res = res^a[i];
	}
	//second step find the position of last set bit from right
	int res_cpy = res;
	int pos = 0;
	
	while(!(res&1)){
		pos++;
		res = res>>1;
	}

	//Generate the reqd mask
	int mask = 1<<pos;

	//Filters the number having set at bit at position
	int setA = 0;
	for(int i=0;i<n;i++){
		if((a[i]&mask)>0){
			setA ^= a[i];
		}
	}
	
	int firstNo = setA;
	int secondNo = res_cpy^setA;

	cout<<firstNo<<" and "<<secondNo<<endl;

	return 0;
}