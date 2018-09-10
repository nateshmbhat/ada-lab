#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/time.h>
#include<time.h>

void mergeSort(int a[] , int low , int high )
{

if(low<high)
{
	int mid = (low+high)/2 ;
	mergeSort(a , low , mid) ; 
	mergeSort(a , mid+1 , high) ; 
	merge(a , low , mid , high) ; 
}

}

void merge(int a[] , int low , int mid , int high)
{
	int i = low , j = mid+1 , k = low  , B[50000] ; 
	
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			B[k++] = a[i++] ; 
		else
			B[k++] = a[j++] ; 
	}

	while(i<=mid) B[k++]  = a[i++] ; 
	while(j<=high) B[k++] = a[j++] ; 

	for(i= low ; i< k ; i++)
		a[i] = B[i] ; 
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
	int i = 0; 
	for(i=0 ; i< n ;i++) printf("%d " , a[i]) ; 
	printf("\n\n") ; 
}


void userInteract(int a[] , int n )
{

	printf("\nEnter size of random array : ") ; 
	scanf("%d" , &n) ; 

	genRand(a , n ) ; 

	printf("Array is : \n" ) ;
	display(a , n ) ; 
	mergeSort(a , 0 , n-1) ; 
	display(a , n) ;
}


int main(void)
{
	srand(time(NULL)) ; 
	int size = 30000 ; 
	int * a  = malloc(size * sizeof(int)) ; 
	int i = 0 , n = 20 ; 
	struct timeval tv ; 
	double s, e ; 
	FILE * fp ; 
	fp = fopen("mergort.dat" , "w") ; 

for(i=100 ; i<size ; i+=100)
{
	gettimeofday(&tv , NULL ) ; 
	genRand(a , i ) ; 
	s = tv.tv_sec + tv.tv_usec/1000000.0 ; 
	mergeSort(a , 0 , i-1) ;
	gettimeofday(&tv , NULL ) ;  
	e = tv.tv_sec + tv.tv_usec/1000000.0 ; 
	fprintf(fp , "%d\t%f\n" , i , e-s) ; 
}

	fclose(fp) ; 
}
