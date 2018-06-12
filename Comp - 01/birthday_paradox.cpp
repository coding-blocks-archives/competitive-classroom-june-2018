#include<iostream>
using namespace std;



int main(){

	int no_of_people = 1;
	int num = 365;
	float denom = 365.0;

	float p;
	cin>>p;
	float prob =1.0;
	
	while(prob>=(1-p)){
		no_of_people++;
		num = num -1;
		prob = prob*(num/denom);
		cout<<"People "<<no_of_people<<" Prob : "<<prob<<endl;
	}

	return 0;
}