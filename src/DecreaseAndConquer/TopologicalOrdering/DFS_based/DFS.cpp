#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std ; 
#define MAX 10

int topological_order(int adj[MAX][MAX] , int n , int cur  , bool visited[] )
{
    visited[cur] = true ; 
    for(int i =0;i < n ; i++) 
        if(adj[cur][i] && !visited[i]) 
            topological_order(adj , n , i , visited) ; 

    cout<< cur+1<<" " ; 
}


int main(void){
    int n ; 
    cout<<"Enter n : " ; cin>>n ;
    int arr[MAX][MAX] = {{0}} ; 
    cout<<"Enter adjacency matrix : " <<endl;  
    for(int i =0 ;i < n ; i++) 
        for(int j =0 ;j  < n ; j++) scanf("%d", &arr[i][j]) ; 
    
    bool visited[MAX] = {0} ; 
    for(int i =0 ;i < n ;i++)
    {
        !visited[i] && topological_order(arr , n , i ,visited ) ; 
    }
}