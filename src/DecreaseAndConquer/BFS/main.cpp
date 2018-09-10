#include<bits/stdc++.h>
#include<iostream>

using namespace std ;

class Queue
{
	public : 
	int *Q , f , r ; 
	Queue(int n ){
	Q = new int[n] ;
		f = r = -1 ;
	}
	
	void enqueue(int a)
	{
		if(f==-1) f = 0 ;
		Q[r++] = a ;
	}
	
	bool isEmpty(){
		return r-f <= 0 ;
	}
	
	int front(){return Q[f] ;}
	
	int dequeue()
	{
		 
		int data =  Q[f++] ;
		if(f==r) f= r = -1 ;
		return data ;  
	}
};


void BFS(int v , int ** adj , bool *visited , int n)
{

	visited[v] = 1 ;
	Queue obj = Queue(n) ;
	
	obj.enqueue(v) ;
	
	while(!obj.isEmpty())
	{
		visited[obj.front()] = 1 ;
		for(int i =0 ; i < n ;i++)
			if( adj[v][i] == 1 && !visited[i] )
				obj.enqueue(i) ;
			cout<< obj.dequeue() << " " ;
	}	
}


int main(void)
{
	int * * adj  = {0} ; 
	
	int n ; 
	cout<<"Enter the number of vertices : " ; 
	cin>> n ; 
	
	adj = new int*[n] ; 
	bool * visited = new bool[n] ;
	
	for(int i =0 ; i < n ; i++){
		adj[i] = new int[n] ;
		visited[i] = 0 ;	
	}
		
	cout<<"Enter adjancency matrix : " ;
	for(int i = 0 ; i < n ; i++){
			for(int j = 0; j < n ; j++)
				cin>>adj[i][j] ;
	}
	
	int v;
	cout<<"Enter source vertex : " ;
	cin>> v ; 
	
	BFS(v-1 , adj , visited , n) ;
	
	for (int k=0; k<n; k++)
{
if(visited[k])
{
cout << "\nVertex " << k+1 << " reachable " << endl;
}
else
{
cout << "\nVertex " << k+1 << " not reachable " << endl;
}
}

		
	
}
