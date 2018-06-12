#include<iostream>
#include<cstring>
using namespace std;

int checkLastBit(int n){
	return n&1;
}

void setIthBit(int &n,int j){
	n = n|(1<<j);
}
bool checkIthBit(int n,int j){
	return n&(1<<j);
}
//Complexity O(LogN)
int countBits(int n){
	int count = 0;
	
	for(;n>0;n=n>>1){
		count += (n&1);
	}

	return count;
}
//Hack - (n&(n-1)) Hack
//O(No of Set Bits <=Log(N))
int countBitsFast(int n){

	int count=0;
	while(n){
		count++;
		//Removes last set bit from n
		n = n&(n-1);
	}
	return count;
}
//Subset/Subsequence Generation N<=20

void filterChars(char *a,int n){

	int j=0;

	while(n>0){
		int last_bit = (n&1);
		if(last_bit){
			cout<<a[j];
		}
		j++;
		n = n>>1;
	}
	cout<<endl;
}

// Subset Sum - Dynamic Programming ...Later classes.

//German Lotto - Problem 



int main(){

	char a[100];
	cin>>a;
	int len = strlen(a);

	for(int i=0;i<(1<<len);i++){
		filterChars(a,i);
	}

	return 0;
}