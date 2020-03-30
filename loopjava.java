import java.util.concurrent.TimeUnit;
import java.lang.Math; 
import java.util.*;
import java.io.*; 

class loopjava 
{ 
    void bubbleSort(int arr[]) 
    { 

        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    // swap arr[j+1] and arr[i] 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                }
    } 

    void selectionSort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
        {  
            int min_idx = i; 
            for (int j = i+1; j < n; j++) 
                if (arr[j] < arr[min_idx]) 
                    min_idx = j; 
  
            // Swap the found minimum element with the first 
            // element 
            int temp = arr[min_idx]; 
            arr[min_idx] = arr[i]; 
            arr[i] = temp; 
        } 
                
    } 

    

    void insertionSort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 1; i < n; ++i) { 
            int key = arr[i]; 
            int j = i - 1; 
  
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 

    void merge(int arr[], int l, int m, int r) 
    { 
        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
  
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
  
  
        int i = 0, j = 0; 
  
        int k = l; 
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
    void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            int m = (l+r)/2; 
  
            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            merge(arr, l, m, r); 
        } 
    } 
  
   
    static int getMax(int arr[], int n) 
    { 
        int mx = arr[0]; 
        for (int i = 1; i < n; i++) 
            if (arr[i] > mx) 
                mx = arr[i]; 
        return mx; 
    } 
  
    static void countSort(int arr[], int n, int exp) 
    { 
        int output[] = new int[n]; // output array 
        int i; 
        int count[] = new int[10]; 
        Arrays.fill(count,0); 
  
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
    
    static void radixsort(int arr[], int n) 
    { 
        int m = getMax(arr, n); 
        for (int exp = 1; m/exp > 0; exp *= 10) 
            countSort(arr, n, exp); 
    } 
    
    static void print(int arr[], int n) 
    { 
        for (int i=0; i<n; i++) 
            System.out.println(arr[i]+" "); 
    } 
}

class Main
{
    // Driver method to test above 
    public static void main(String args[]) 
    { 
        loopjava lp=new loopjava();
       
    	int n=10;
       	int num[]=new int[n];
       	Random random=new Random();
  
	for(int i=0; i<n; i++)             //generation of random numbers
        {
             num[i]=1+ random.nextInt(n*10);
        }
    
            int ch;
            do
            {
            	Scanner sc=new Scanner(System.in);
            	
            	System.out.println("Select Sorting method: ");
            	System.out.println("1. Bubble Sort");
            	System.out.println("2. Selection Sort");
            	System.out.println("3. Insertion Sort");
            	System.out.println("4. Merge Sort");
            	System.out.println("5. Radix Sort");
        
            	ch=sc.nextInt();
            	double startTime;
            	double endTime;
            	double duration;
            	
            	int array[]=new int[n];
            	for(int k=0; k<array.length; k++)
        	{
                    array[k]=num[k];
		}
            	
            	switch(ch)
            	{
            		case 1:
				startTime = System.nanoTime();
            		    
            			lp.bubbleSort(array);
            			System.out.println("\nSorted array"); 
        			lp.print(array, n);
                		
                		endTime = System.nanoTime();
           	 	        duration = (endTime - startTime);  //Total execution time in milli seconds
            	        	System.out.println("Elapsed time: "+duration);
            		break;

            		case 2:
            			startTime = System.nanoTime();
            		    
				lp.selectionSort(array);
				System.out.println("\nSorted array"); 
				lp.print(array, n);

				endTime = System.nanoTime();
				duration = (endTime - startTime);  //Total execution time in milli seconds
				System.out.println("Elapsed time: "+duration);
            		break;
        
            		case 3:
            		    	startTime = System.nanoTime();
            		    
        		        lp.insertionSort(array);
        		        System.out.println("\nSorted array"); 
        			lp.print(array, n);
        		        
        		        endTime = System.nanoTime();
           	 	        duration = (endTime - startTime);  //Total execution time in milli seconds
            	        	System.out.println("Elapsed time: "+duration);
        		    break;
        		    
        		    
        		    case 4:
        		        
                        	startTime = System.nanoTime();
                        
				lp.sort(array, 0, array.length-1); 
				  
				System.out.println("\nSorted array"); 
        			lp.print(array, n);
				        
				endTime = System.nanoTime();
           	 	        duration = (endTime - startTime);  //Total execution time in milli seconds
            	        	System.out.println("Elapsed time: "+duration);
        		    break;

        		    case 5:
        		        startTime = System.nanoTime();
        
       	 			lp.radixsort(array, n); 
  
        			System.out.println("\nSorted array"); 
        			lp.print(array, n);

        			endTime = System.nanoTime();

        			duration = (endTime - startTime);  //Total execution time in milli seconds
        
        			System.out.println("Elapsed time: "+duration);
        		    break;
            	}
            }while(ch<=6);
            
    } 
}
