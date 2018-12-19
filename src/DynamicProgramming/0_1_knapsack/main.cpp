#include<bits/stdc++.h>

using namespace std ;

typedef struct{
	int value , weight ; 
} Item ; 


void getItems(Item items[] , int n , int mem[][100] , int cap){
	int i = n , j = cap ; 
	while(i>=1 && j>=1){
		if(mem[i][j]!=mem[i-1][j]){
			cout<<" Item " << i << " included." <<endl; 
			i-=1 ; j-=items[i].weight ; 
		}
		else {
			i-=1 ; 
		}
	}
}


int knapsack(Item items[] , int n , int cap )
{
	int mem[100][100]={0} ; 
	mem[0][0] = 0 ; 

	for(int i =1 ;i <= n ; i++){
		for(int j=1 ; j<= cap ; j++){

			if(j>=items[i-1].weight)
			{
				mem[i][j] = max(mem[i-1][j] , items[i-1].value+mem[i-1][j-items[i-1].weight]) ;
			}

			else
				mem[i][j] = mem[i-1][j] ;
		}	
	}
	getItems(items , n , mem ,  cap) ;
	return mem[n][cap] ; 
}




int main(void)
{ 
	int n ; Item items[100] ; cout<<"Enter n : " ; cin>> n ; 
	int v , w ;

	for(int i =0 ; i< n; i++)
	{
		cout<<"Enter value and weight : " ; cin>>v>>w ; 
		items[i] = {v , w} ; 
	}
	cout<<"Enter capacity : " ; int cap ; cin>>cap ; 
	cout<< " res = " << knapsack(items , n , cap ) ; 
}