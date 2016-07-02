#include <stdio.h>

void bubbleSort(int [], int);
void printArray(int [] , int);


int main()
{
  int array_size = 4;
  int array[4] = {2, 1, -4, 32};
  

  bubbleSort(array, array_size);
  printArray(array, array_size);
  
  return 0;
}


void printArray(int x[], int size)
{
  int i = 0;
  for(i=0; i<size; i++)
    printf("array[%d] = %d\n", i, x[i]);
}



void bubbleSort(int x[], int size)
{
  int temp = 0, i = 0, j = 0;

  for(i=size-2; i>=0; i--)
    {
      for(j=0; j<size; j++)
	{
	  if(x[j] > x[j+1])
	    {
	      temp = x[j];
	      x[j] = x[j+1];
	      x[j+1] = temp;
	    }
	}
    }
	     
}

