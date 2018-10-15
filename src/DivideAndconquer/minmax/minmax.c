#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int min , max ;
} node;


node minmax(int a[] , int low , int high)
{
  if(low==high){
       node mynode = {a[low] , a[low]}  ;
       return mynode ;
  }
   
   int mid  = (high+low)/2 ;
   node left = minmax( a, low , mid) ;
   node right = minmax(a , mid+1 , high) ;
   node res = {left.min<right.min?left.min : right.min , left.max>right.max ? left.max : right.max} ;  
   return res ; 
}



int main(void)
{
	srand(time(NULL)) ; 
  int a[100] = {0} ; 
  int i = 0 , n = 20 ;

  printf("Array is : \n" ) ;
  a[0] = rand()%20 ;
  printf("%d "  , a[i]) ; 
  
  for(i=1 ; i < n ; i++)
  {
  	a[i] = a[i-1] + rand()%10 ; 
  	printf("%d "  , a[i]) ; 
  }

printf("\n\n") ; 

node res = minmax(a , 0 , n-1) ; 
 
printf("Minimum = %d  , and maximum = %d\n" , res.min , res.max) ;
}
