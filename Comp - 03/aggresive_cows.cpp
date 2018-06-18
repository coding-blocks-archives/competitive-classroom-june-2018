#include<iostream>
using namespace std;

bool canPlace(int *stalls,int n,int cows,int dist){

	int pos = stalls[0];
	int c = 1;
	for(int i=1;i<n;i++){
		if(stalls[i]-pos>=dist){
			c++;
			pos = stalls[i];
			if(c==cows){
				return true;
			}
		}
	}
	return false;
}

int binarySearch(int *stalls,int n,int cows){
	int s=0;
	int e = stalls[n-1]-stalls[0];

	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;

		if(canPlace(stalls,n,cows,mid)){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}


	}
	return ans;
}

int main(){
	
	int stalls[] = {1,2,4,8,9};
	int cows = 3;
	cout<<binarySearch(stalls,5,cows)<<endl;


	return 0;
}