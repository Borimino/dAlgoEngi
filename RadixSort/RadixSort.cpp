#include<iostream>
#include <cstdlib>
#include <vector>
#include <limits.h>

using namespace std;

int N = 1000;
//int* A = new int[N];
//int maxn = 10000;
long maxn = LONG_MAX;
int MAX_N = 5000;

//vector<int> A;
vector<long> A;
 
// A utility function to get maximum value in arr[]
//int getMax(int arr[], int n)
//int getMax(vector<int> arr, int n)
long getMax(vector<long> arr, int n)
{
    //int mx = arr[0];
    long mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void init()
{
	//vector<int> a(N, 0);
	vector<long> a(N, 0);
	//A = new int[N];
	A = a;

	for (int i=0; i < N; i++) {
		A[i] = rand() % maxn;
	}
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
//void countSort(int arr[], int n, int exp)
//void countSort(vector<int> arr, int n, int exp)
vector<long> countSort(vector<long> arr, int n, int exp)
{
    //int output[n]; // output array
    vector<long> output(n, 0); // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

	//cout << "#TEST" << endl;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

	//cout << "#TEST" << endl;
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
     //cout << "#TEST" << endl;

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    //for (i = 0; i < n; i++)
        //arr[i] = output[i];
	return output;
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
//void radixsort(int arr[], int n)
//void radixsort(vector<int> arr, int n)
void radixsort(vector<long> arr, int n)
{
    // Find the maximum number to know number of digits
    //int m = getMax(arr, n);
    long m = getMax(arr, n);

	//cout << "#TEST" << endl;
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
	{
		//cout << "#TEST" << endl;
        arr = countSort(arr, n, exp);
		//cout << "#TEST" << endl;
	}
	A = arr;
}
 
// A utility function to print an array
//void print(int arr[], int n)
//void print(vector<int> arr, int n)
void print(vector<long> arr, int n)
{
	cout << "#";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
	cout << endl;
}

int testConstantRadix()
{
	init();
    cout << "#initDone" << endl;
	print(A, N);
	cout << "#-------------------------------------------------" << endl;
	clock_t start, end;
	start = clock();
    radixsort(A, N);
	end = clock();
    print(A, N);
	double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
	cout << N << " " << time << endl;
	return 0;
}

void testRisingNRadix()
{
	for (int n_1 = 2; n_1 < MAX_N; n_1+=100)
	{
		N = n_1;

		testConstantRadix();
	}
}
 
// Driver program to test above functions
int main()
{
    //testConstantRadix();
	testRisingNRadix();
    return 0;
}
