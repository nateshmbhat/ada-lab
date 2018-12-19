#include<bits/stdc++.h>
using namespace std ;
int arr[100][100] = {0} ; 


void display(int n ){
    for(int i =0 ;i < n ; i++){
        for(int j =0 ; j < n ; j++){
            cout<< arr[i][j] << " " ; 
        }
        cout<<endl; 
    }
    cout<<endl<<endl; 
}



bool isSafe(int n , int row , int col){
    for(int i =0 ;i < n ; i++){
        if(arr[i][col] || arr[row][i]) return false ; 
    }
    // top right
    for(int i = row , j=col ; i>=0 && j<n ;i-- , j++)
        if(arr[i][j])return false ; 

    // top left
    for(int i = row , j=col ; i>=0 && j>=0 ;i-- , j--)
        if(arr[i][j])return false ; 

    return true ; 
}

bool NQueen(int n , int row ){
    if(row>=n){
        display(n) ;
        return false ; 
    }

    for(int i=0 ; i < n ; i++){
        if(isSafe(n ,row , i))
        {
            arr[row][i] = 1 ;
            if(NQueen(n , row+1))
                return true ; 
            arr[row][i] = 0 ; 
        }
    }
    return false ; 
}

int main(void) { 
    int n; cout<<"Enter n : " ; cin>>n ; 
    NQueen(n , 0 ) ;     
}
