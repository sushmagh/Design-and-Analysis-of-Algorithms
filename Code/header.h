#include<stdio.h>
void swap(int *x,int *y);
void bubbleSort(int arr[], unsigned long int n);
int mergesort(int *a,unsigned long int n,unsigned long comp);
int merge(int *B, int *C, int *arr, unsigned long int lsize,unsigned long int rsize,unsigned long comp);
void quicksort(int *arr,int l,int r);
void selectionSort(int *arr,unsigned long int n) ;
void MERGE(int *arr,unsigned long int size);
void quick_sort(int *arr,unsigned long int size);
int *random_generate(unsigned long int size,int seed);
void fileWrite1(char* filename1,unsigned long int size,double time);
void fileWrite2(char* filename2,unsigned long int size,unsigned long int cmp);
void quick__sort(int array[], int start_index, int end_index);
int partition(int *arr, int l, int r);
