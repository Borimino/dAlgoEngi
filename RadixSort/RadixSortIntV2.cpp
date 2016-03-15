#include<iostream>
#include <cstdlib>
#include <vector>
#include <limits.h>

using namespace std;

int N = 100;
long maxn = INT_MAX;
int MAX_N = 5000;

vector<long> A;
 
// A utility function to get maximum value in arr[]
long getMax(vector<long> arr, int n)
{
    long mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void init()
{
	vector<long> a(N, 0);
	A = a;

	for (int i=0; i < N; i++) {
		A[i] = rand() % maxn;
	}
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
vector<long> countSort(vector<long> arr, int n, int exp)
{
    vector<long> output(n, 0); // output array
	vector<long> storage(n*10, 0); // storage array
    //int i, count[10] = {0};
	vector<int> next(10, 0);

	for (int i = 0; i < 10; i++)
	{
		next[i] = i*n;
	}

	for (int i = 0; i < n; i++)
	{
		int key = (arr[i]/exp)%10;
		storage[next[key]] = arr[i];
		next[key] += 1;
	}

	int nextOut = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i*n; j < next[i]; j++) {
			output[nextOut] = storage[j];
			nextOut += 1;
		}
	}

	//print(output, n);
 
	//cout << "#TEST" << endl;

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	//for (int i = 0; i < n; i++)
	//{
		//cout << "#TEST" << i << endl;
		return output;
		//cout << "#TEST" << i << endl;
	//}

	//cout << "TEST" << endl;
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(vector<long> arr, int n)
{
    // Find the maximum number to know number of digits
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
