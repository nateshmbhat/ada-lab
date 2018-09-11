#include<bits/stdc++.h>
using namespace std ;

void topological(int v ,bool *visited , int **adj , int n ){
    for(int i =0 ; i< n ; i++){
        if(adj[v][i] && !visited[i]){
            visited[i] = 1 ; 
            topological(i , visited , adj , n ) ; 
            cout<< " " << i+1 ; 
        }
    }
    if(!visited[v]){
        visited[v] =1 ; 
        cout<<" " <<v+1 ; 
    }
}


int main(void){
    int n ; cout<<"Enter number of vertices : " ; 
    bool visited[100] = {0} ; 
    cin>>n ; 
    cout<<"Enter adj matrix : "<<endl;  ; 
    int **adj = new int*[n]  ;for(int i =0; i<n ; i++)adj[i] = new int[n] ; 
    for(int i =0 ; i < n ; i++)
        for(int j =0 ; j< n ; j++)
            cin>>adj[i][j] ;
    
    cout<<"\nTopological sorting is : " <<endl; 
    for(int i =0 ; i < n ; i++)
        topological(i  , visited , adj , n) ; 
}