
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/time.h>
#include<time.h>
#include<stdbool.h>


void swap(int * a , int *b){
	int temp = *a ; 
	*a = *b ;
	*b = temp ;
}


//CONSIDERING OUR ARRAY STARTS FROM INDEX 1
void heapSort(int a[] , int n )
{
	constructHeap(a , n ) ;

	int i =0 ;

	int heapsize = n ;

	while(heapsize>0){
		swap(&a[0] , &a[heapsize--]) ;
		heapify(a ,heapsize , 0) ;
	}
}


void constructHeap(int a[] , int n )
{
	int i =0 ;
	for(i = n/2 ; i>=0 ; i--)
	{
		heapify(a , n ,  i) ;
	}
}



void heapify(int a[] , int  n , int keyIndex )
{
	int v = a[keyIndex] ;
	bool heap = false ; 
	int j = 0 , k = keyIndex ;

	while(!heap && k*2<=n )
	{
		j  = k*2 ;
		
		if(j<n){
			//two children
			if(a[j+1]>a[j]) j+=1 ;
		}

		if(a[j]>v){
			a[k] = a[j] ;
			k = j ;
		}
		else
			heap  = true ; 
	}
	a[k] = v ;
}



void genRand(int a[] , int n )
{
	int i ; 
	for(i=0 ; i < n ; i++)
	{
		a[i] = rand()%100 ;
	}
}


void display(int a[] , int n )
{
	int i = 1; 
	for(i=1 ; i< n ;i++) printf("%d " , a[i]) ; 
	printf("\n\n") ; 
}


void userInteract(int a[] , int n )
{

	printf("\nEnter size of random array : ") ; 
	scanf("%d" , &n) ; 
	n+=1 ;

	genRand(a , n ) ; 

	printf("Array is : \n" ) ;
	display(a , n ) ; 
	heapSort(a , n ) ; 
	display(a , n) ;
}


int main(void)
{
	srand(time(NULL)) ; 
	int size = 100000 ; 
	int * a  = malloc(size * sizeof(int)) ; 
	int i = 0 , n = 20 ; 
	struct timeval tv ; 
	double s, e ;
	printf("\n1. Plot graph\t2.heapSort\t3.Exit\nEnter choice : ") ; 
	int ch ;
	FILE * fp ; 

	scanf("%d" , &ch) ; 

	switch(ch)
	{
		case 1:

				
			fp = fopen("heapsort.dat" , "w") ; 

			for(i=100 ; i<size ; i+=100)
			{
				printf("i = %d\n" , i) ; 

				gettimeofday(&tv , NULL ) ; 
				genRand(a , i ) ; 
				s = tv.tv_sec + tv.tv_usec/1000000.0 ; 
				heapSort(a ,i ) ;
				gettimeofday(&tv , NULL ) ;  
				e = tv.tv_sec + tv.tv_usec/1000000.0 ; 
				fprintf(fp , "%d\t%f\n" , i , e-s) ; 
			}

				fclose(fp) ;
			break ;

		case 2 : 
			userInteract(a , n) ;
			break ; 			

		default : exit(1) ; 
	}
}
