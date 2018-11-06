#include<bits/stdc++.h>
using namespace std ; 

int N ; 
bool flag =1; 

void display(stack<int> stk )
{
	flag = 0 ; 
	cout<<" { "  ; 
	while(!stk.empty()){
		cout<< stk.top() <<" , " ; 
		stk.pop() ; 
	}
	cout<<"}" << endl <<endl; 
}


 void sumOfSubsets(vector<int> subsets , int i , int sum , stack<int>& stk ){
	if(sum==0) { 
		display(stk) ; return ; 
	}

	if(sum<0 || i<0 ) return ; 

	stk.push(subsets[i]) ; 
	sumOfSubsets(subsets , i-1 , sum-subsets[i] , stk) ; 
	stk.pop() ; 
	sumOfSubsets(subsets , i-1 , sum , stk ) ; 
}


int main(void){
	vector<int> subs = vector<int>() ;
	stack<int> sumSubs = stack<int>() ;
	int temp ; 
	cout<<"Enter number of elements : " ; cin>>N ; 
	cout<<"Enter elements : " ; 

	for(int i =0 ;i < N; i++)
	{
		cin>>temp ; 
		subs.push_back(temp) ; 
	}

	cout<<"Enter total sum : " ; int sum ; cin>>sum ; 
	sumOfSubsets(subs , N-1 ,  sum , sumSubs ) ; 
	if(flag)
		cout<<" No solution !" ; 
}