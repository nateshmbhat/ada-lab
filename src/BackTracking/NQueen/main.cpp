#include<bits/stdc++.h>
#define MAX 64
using namespace std ; 

bool isSafe(int board[MAX][MAX] , int n , int posrow , int poscol){
	for(int i =0 ;i < n ; i++){
		if (board[i][poscol] || board[posrow][i]) return 0 ; 
	}

	for(int i=posrow , j=poscol ; i>=0&&j>=0 ; i-- , j--){	
		if(board[i][j])return 0 ; 
	}

	for(int i=posrow , j=poscol ; i>=0&&j<n ; i-- , j++){	
		if(board[i][j])return 0 ; 
	}
	return true ; 
}


bool NQueen(int board[MAX][MAX] , int row ,  int n){
	if(row>=n)return 1 ;

	for(int i =0 ;i < n ; i++){
		if(isSafe(board , n , row , i ))
		{
			board[row][i] = 1 ; 
			if(NQueen(board , row +1 , n )) 
				return true ; 
			board[row][i] = 0 ; 
		}
	}
	return  false; 
}


int main(void){
	int n  ; cout<<"Enter N : " ; cin>>n ;
	int board[MAX][MAX] = {0} ; 
	NQueen(board , 0 , n) ; 
	for(int i =0 ;i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
			cout<< board[i][j] << " " ; 
		cout<<endl; 
	}
}
