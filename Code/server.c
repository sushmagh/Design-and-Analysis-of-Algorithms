#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<math.h>
#include<time.h>
unsigned int comaparisons_quick=0;
unsigned long count_quick = 0;
int *random_generate(unsigned long int size,int seed)
{
    srand(seed);
    int *ran = (int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        *(ran+i) = rand();
    }
    return ran;
}
//1.Bubble Sort
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubbleSort(int *arr, unsigned long int n) 
{
    printf("Bubble sort with %lu input size: \n",n);
    double time_spent = 0.0;
    unsigned long comparisons_bubble = 0;
    
    int i, j;
    clock_t begin = clock(); 
    for (i = 0; i < n-1; i++)       
    {
         
       for (j = 0; j < n-i-1; j++)  
           {
               comparisons_bubble++;
               if (*(arr+j) > *(arr+(j+1)))
               {
                    
                    swap(&(*(arr+j)),&(*(arr+(j+1)))); 
               }
           }
    }
    
    clock_t end = clock(); 
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu\n ; Time Spent:%lf\n",comparisons_bubble,time_spent);
    fileWrite1("bubblesort_timespent.txt",n,time_spent);
    fileWrite2("bubblesort_comparisions.txt",n,comparisons_bubble);
}


//2.merge sort
void MERGE(int *arr, unsigned long int size)
{
    printf("Merge sort with %lu input size: \n",size);
    double time_spent = 0.0;
    unsigned long int comparisions_merge = 0;
    clock_t begin = clock(); 
    int i, j;
    unsigned long int cmp = mergesort(arr,size,comparisions_merge);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu\n ; Time Spent:%lf\n",cmp,time_spent);
    fileWrite1("mergesort_timespent.txt",size,time_spent);
    fileWrite2("mergesort_comparisons.txt",size,cmp);
    
}
int merge(int *B, int *C, int *arr, unsigned long int lsize,unsigned long int rsize,unsigned long int comparisions_merge)
{
    int size=lsize+rsize;
    int i=0,j=0,k=0;
    while(i<lsize && j< rsize)
    {
        
        comparisions_merge++;
        
        if(*(B+i) <=*(C+j))
        {
            
            *(arr+k) = *(B+i);
            i++;
        }
        else
        {
            
            *(arr+k)=*(C+j);
            j++;
        }
        k++;
    }
    if(i==lsize)
    {
        for(;j<rsize;j++)
        {
            
            *(arr+k)=*(C+j);
            k++;
        }
    }
    else
    {
        for(;i<lsize;i++)
        {
            
            *(arr+k) = *(B+i);
            k++;
        }
    }
    return comparisions_merge;

}
int mergesort(int *arr, unsigned long int size,unsigned long int comparisions_merge)
{
    
    int lsize,rsize,k=0;
    
    int *B = (int *)malloc(size*sizeof(int));
    int *C = (int *)malloc(size*sizeof(int));
    if (size>1)
    {
        lsize=floor(size/2);
        rsize=size-lsize;
        for(int i=0;i<lsize;i++)
            *(B+i)=*(arr+i);
        
        
        for(int i=lsize;i<size;i++){
            
            
            *(C+k) = *(arr+i);
            k++;
        }
        
        comparisions_merge = mergesort(B,lsize,comparisions_merge);
        comparisions_merge = mergesort(C,rsize,comparisions_merge);
        comparisions_merge = merge(B,C,arr,lsize,rsize,comparisions_merge);
        

        
    }
    free(B);
    free(C);
    return comparisions_merge;
    
}


 

//quick sort
int partition(int *arr, int l, int r)
{
    int p;
    int i,j;
    p=*(arr+l);
    i=l;
    j=r+1;
    do{
        
        do{
            comaparisons_quick++;
            i++;
            
        }while(*(arr+i)<p);
        do
        {
            comaparisons_quick++;
            j--;
            
        }while(*(arr+j)>p);
        swap(&(*(arr+i)),&(*(arr+j)));
        
    }while(i<j);
    
    swap(&(*(arr+i)),&(*(arr+j)));
    swap(&(*(arr+l)),&(*(arr+j)));
    return j;
}
void quicksort(int *arr,int l,int r)
{
    int s;

    if(l<r)
    {
        s=partition(arr,l,r);
        quicksort(arr,l,s-1);
        quicksort(arr,s+1,r);
    }
    
}
void quick_sort(int *arr,unsigned long int size)
{
    printf("Quick sort with %d input size: \n",size);
    double time_spent = 0.0;
    clock_t begin = clock();
    quicksort(arr,0,size-1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu\n ; Time Spent:%lf\n",comaparisons_quick,time_spent);
    fileWrite1("quicksort_timespent.txt",size,time_spent);
   fileWrite2("quicksort_comparisons.txt",size,comaparisons_quick);
}



//selection sort
void selectionSort(int *a,unsigned long int size)
{
    printf("Selection Sort with %lu input size: \n",size);
    double time_spent = 0.0;
    unsigned long comparisions_selection = 0;
    clock_t begin = clock(); 

    unsigned long i,j,min;
    int temp;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++)
        {
            comparisions_selection++;
            if(a[j] < a[min])
            {
                
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu\n ; Time Spent:%lf\n",comparisions_selection,time_spent);
    fileWrite1("selectionsort_timespent.txt",size,time_spent);
    fileWrite2("selectionsort_comparisions.txt",size,comparisions_selection);
}

void fileWrite1(char* filename1,unsigned long int size,double time)
{
    FILE *fptr1;
    fptr1=fopen(filename1,"a");
    if(fptr1==NULL)
    {
        printf("ERROR");
    }
    else
    {
        fprintf(fptr1,"when input size is %lu : \n Time : %lf\n\n",size,time);
        fclose(fptr1);
    }
}
void fileWrite2(char* filename2,unsigned long int size, unsigned long int cmp)
{
    FILE *fptr1;
    fptr1=fopen(filename2,"a");
    if(fptr1==NULL)
    {
        printf("ERROR");
    }
    else
    {
        fprintf(fptr1,"when input size is %lu :  comaprisons :%lu\n\n",size,cmp);
        fclose(fptr1);
    }

}