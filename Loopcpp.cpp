
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<unistd.h>
#include <time.h>
using std::cout;
using std::endl;
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)

	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
	cout << endl;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}
}
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];


	i = 0;
	j = 0;
	k = l;
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


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


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

		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	int m = getMax(arr, n);

	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

int main()
{
    int arr[10],num1[10],num2[10],num3[10],num4[10],i,choice,x;
    for(i=0;i<5;i++)
    {
       for(i=0;i<10;i++)
       {
          arr[i]=rand()%100;
          num1[i]=arr[i];
          num2[i]=arr[i];
          num3[i]=arr[i];
          num4[i]=arr[i];
       }
	   int n = 10;
	   do
	   {
	   cout<<"\tSELECT SORTING METHOD"
	       <<"\t\n1.Bubble Sort."
	       <<"\t\n2.Selection Sort."
	       <<"\t\n3.Insertion Sort."
	       <<"\t\n4.Merge Sort."
	       <<"\t\n5.Radix Sort";
	   cin>>choice;
	   switch(choice)
	   {
	       case 1 :
	             {
	              clock_t t;
	              t = clock();
                  size_t size = 100000;
	              bubbleSort(arr, n);
	              cout<<"Sorted array: \n";
	              printArray(arr, n);
	              t = clock() - t;
	              cout << "time: " << t << " miliseconds" << endl;
                  cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	              cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;
	              break;

	             }
	       case 2 :
	              {
	              clock_t t1;
	              t1 = clock();
                  size_t size1 = 100000;
                  printArray(num1, n);
	              selectionSort(num1, n);
	              cout << "Sorted array: \n";
	              printArray(num1, n);
	              t1 = clock() - t1;
	              cout << "time: " << t1 << " miliseconds" << endl;
                  cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	              cout << "time: " << t1*1.0/CLOCKS_PER_SEC << " seconds" << endl;
	              break;

	              }
	       case 3 :
	               {
	               clock_t t2;
	               t2 = clock();
                   size_t size2 = 100000;
	               insertionSort(num2, n);
	               cout<<"Sorted array: \n";
	               printArray(num2, n);
	               t2 = clock() - t2;
	               cout << "time: " << t2 << " miliseconds" << endl;
                   cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	               cout << "time: " << t2*1.0/CLOCKS_PER_SEC << " seconds" << endl;
	               break;

	               }
	       case 4:
	               {
	               clock_t t3;
	               t3 = clock();
                   size_t size3 = 100000;
	               mergeSort(num3, 0, n - 1);
                   cout<<"Sorted array: \n";
	               printArray(num3, n);
	               t3 = clock() - t3;
	               cout << "time: " << t3 << " miliseconds" << endl;
                   cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	               cout << "time: " << t3*1.0/CLOCKS_PER_SEC << " seconds" << endl;
	               break;

	               }

	       case 5:
	              {
	               clock_t t4;
	               t4 = clock();
                   size_t size4 = 100000;
	               radixsort(num4, n);
	               cout<<"Sorted array: \n ";
	               printArray(num4, n);
	               t4 = clock() - t4;
	               cout << "time: " << t4 << " miliseconds" << endl;
                   cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	               cout << "time: " << t4*1.0/CLOCKS_PER_SEC << " seconds" << endl;
	               break;

	              }
	       default:
	              {
	                  cout<<"Wrong input";

	              }

	   }

	   }while(choice<6 && choice>0);
    }
	return 0;
}
