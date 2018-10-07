#include<stdlib.h>
#include<stdio.h>


void swap(int * a ,int * b){
    int temp = *a ; *a = *b ; *b = temp ; 
}

int partition(int * arr , int l , int h ){
    int i = l ; 
    int j = h+1 ; 
    int p = arr[l]  ;
    do{
        do{i+=1 ; }while(arr[i]<p);
        do{j-=1 ; }while(arr[j]>p) ; 
        swap(&arr[i] , &arr[j]) ; 
    }while(i<j);
    
    swap(&arr[i] ,& arr[j]) ; 
    swap(&arr[j] , &arr[l]) ; 
    return j ; 
}


void quicksort(int *arr , int l , int h ){
    if(l<h){
        int p = partition(arr , l , h ) ; 
        quicksort(arr , l , p-1) ; 
        quicksort(arr , p+1 , h) ; 
    }
}

void genRand(int * arr , int n ){
    int i =0 ; 
    srand(time(0)) ; 

    for(i =0  ; i < n ; i++) 
        arr[i] = rand()%100 ; 
}
void display(int * arr ,  int n ){int i =0 ; for(i =0 ; i< n ; i++) printf("%d " , arr[i]) ;puts("") ;    }


int main(void)
{
    long n = 100000  , i ; 
    int * arr = (int * )malloc(sizeof(int)*n) ; 
    int size ;
    double start , end ; 
    struct timeval tv ;
    int ch ; FILE * fp ; 

    while(1){
        printf("\n1.Quicksort 2.Plotgraph 3.Exit :  ") ; scanf("%d" , &ch) ; 
        if(ch==1){
            printf("Enter n : ") ;scanf("%d" , &size) ; 
            genRand(arr , size) ; 
            display(arr , size) ; 
            quicksort(arr , 0 , size-1) ; 
            display(arr , size) ; 
        }
        else if(ch==2){
            fp = fopen("quicksort.dat" , "w") ; 
            for(i = 100 ;i < 50000; i+=100){
                genRand(arr , i) ; 
                gettimeofday(&tv , 0) ; 
                start = tv.tv_sec + tv.tv_usec/1000000.0 ; 
                quicksort(arr , 0 , i-1) ; 
                gettimeofday(&tv , 0) ; 
                end = tv.tv_sec + tv.tv_usec/1000000.0 ; 
                fprintf(fp , "%d\t%f\n" , i , end-start ) ; 
            }
            fclose(fp) ; 
        }
    }
}
