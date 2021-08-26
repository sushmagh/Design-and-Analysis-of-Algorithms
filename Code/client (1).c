
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"header.h"

void main()
{
    for(int size=100000;size <= 1000000;size+=50000)
    {
        for(int choice=0;choice<=3;choice++)
        {
            switch(choice)
            {
                case 0:
                {
                    int *arr = random_generate(size,1);
                    bubbleSort(arr,size);
                    free(arr);
                    break;
                }
                case 1:
                {
                    int *arr = random_generate(size,1);
                    selectionSort(arr,size);
                    free(arr);
                    break;
                }
                case 2:
                {
                    int *arr = random_generate(size,1);
                    MERGE(arr,size);
                    free(arr);
                    break;
                }
                case 3:
                {
                    int *arr = random_generate(size,1);
                    quick_sort(arr,size);
                    free(arr);
                    break;
                }
            }
        }
    }

}