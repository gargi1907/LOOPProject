
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#define SIZE 10000

int myArray[SIZE - 1];
void bubbleSort(int x[]);
void insertionSort(int myArray[]);
void selectionSort(int myArray[]);
void merge(int arr[], int l, int m, int r) ;
void mergeSort(int arr[], int l, int r) ;
int getMax(int array[], int n);
void countingSort(int array[], int size, int place);
void radixsort(int array[], int size);
void swapf(int x, int y);
void init();

int main()
{
	int c=0;
	clock_t t;
	double time_taken=0.0;
	do
	{
		printf("1.Bubble sort\n");
		printf("2.insertion sort\n");
		printf("3.selection sort\n");
		printf("4.merge sort\n");
		printf("5.radix sort\n");
		printf("6.exit\n");
		scanf("%d",&c);

		switch(c)
		{
		case 1:
			init();
			t = clock();
			bubbleSort(myArray);
			t = clock() - t;
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			printf("bubbleSort took %f seconds to execute \n", time_taken);
			break;

		case 2:
			init();
			t = clock();
			insertionSort(myArray);
			t = clock() - t;
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			//printSorted();
			printf("insertionSort took %f seconds to execute \n", time_taken);
			break;

		case 3:
			init();
			t = clock();
			selectionSort(myArray);
			t = clock() - t;
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			printf("selectionSort took %f seconds to execute \n", time_taken);
			break;

		case 4:
			init();
			t = clock();
			mergeSort(myArray, 0, SIZE - 1);
			t = clock() - t;
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			printf("mergeSort took %f seconds to execute \n", time_taken);
			break;

		case 5:
			init();
			t = clock();
			radixsort(myArray, SIZE);
			t = clock() - t;
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			printf("radixsort took %f seconds to execute \n", time_taken);
			break;


		}

	}while(c!=6);

	return 0;
}
void bubbleSort(int x[])
{
	int i, j;

	for(i = 1; i < SIZE; i++)
	{
		for( j = 0; j < SIZE - 1; j++)
		{
			if(myArray[j] > myArray[j+1])
			{
				swapf(j, j+1);
			}

		}
	}
}
void selectionSort(int myArray[])
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < SIZE-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < SIZE; j++)
			if (myArray[j] < myArray[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swapf(min_idx,i);
	}
}
void insertionSort(int myArray[])
{
	int i, key, j;
	for (i = 1; i < SIZE; i++)
	{
		key = myArray[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
		while (j >= 0 && myArray[j] > key)
		{
			myArray[j + 1] = myArray[j];
			j = j - 1;
		}
		myArray[j + 1] = key;
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
       are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
       are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}
void init()
{
	int i;
	for( i = 0; i < SIZE - 1; i++)
	{
		myArray[i] = rand()%10000;
	}
}
void swapf(int x,int y)
{
	int temp;
	temp = myArray[x];
	myArray[x] = myArray[y];
	myArray[y] = temp;

}
int getMax(int array[], int n)
{
	int i=0;
	int max = array[0];
	for ( i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
void countingSort(int array[], int size, int place)
{
	int i=0;
	int output[size + 1];
	int max = (array[0] / place) % 10;

	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	int count[max + 1];

	for ( i = 0; i < max; ++i)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for ( i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for ( i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for ( i = 0; i < size; i++)
		array[i] = output[i];
}
void radixsort(int array[], int size)
{
	int max = getMax(array, size);
	int place =0;
	for ( place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}









