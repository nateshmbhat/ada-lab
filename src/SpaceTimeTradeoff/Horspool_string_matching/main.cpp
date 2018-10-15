#include<bits/stdc++.h>

using namespace std ; 

void shiftTable(int table[] , string p){
	for(int i =0 ; i < 128 ; i++)
		table[i] = p.length() ; 
	for(int i = 0 ; i < p.length()-1 ; i++){
		table[p[i]] = p.length()-i-1 ;
	}
}

int horspool(string T , string P , int table[]){
	int m = P.length()  , n = T.length() ; int i =m-1 ; 
	while(i<n){
		int k = 0 ; 
		while(k<m && P[m-1-k]==T[i-k])	k+=1 ; 
		if(k==m){return i-m+1 ;}
		else i+=table[T[i]] ;
	}
	return -1 ;
}

int main(void){
	string T , P ;
	cout<<"Enter Text : " ; 
	getline(cin , T) ; 
	cout<<"Enter Pattern : " ; 
	getline(cin , P) ;  
	int table[128] ;
	shiftTable(table , P) ; 
	int res = horspool(T , P , table) ;
	if(res>=0)
		cout<< "found at position : " << res <<endl; 
	else cout<< "Not found !" <<endl; 
}
