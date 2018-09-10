#include<stdio.h>
#include<stdlib.h>


int linearSearch(int a[] , int n  , int key , int i ) 
{
	return i>=n ? -1 : key==a[i]? i : linearSearch(a , n , key  ,i+1) ; 
}

int main(void)
{
	srand(time(NULL)) ; 
	int a[100] = {0} ; 
	int i = 0 , n = 20 ; 

	printf("Array is : \n" ) ; 
	for(i=0 ; i < n ; i++)
	{
		a[i] = rand()%100 ; 
		printf("%d "  , a[i]) ; 
	}
		printf("\n\n") ; 
		int key = 30 ; 

	printf("\nKey = %d\n\n" , key) ; 
		
	int res = linearSearch(a , n , key , 0) ; 

	printf(res<0? "Element not found !\n" : "Element found at position : %d \n" , res) ; 
}