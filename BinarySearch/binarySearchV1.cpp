#include <iostream>
#include <cstdlib>

using namespace std;

const int N=1000000000;

int A[N];

void init()
{
	for (int i = 0; i < N; i++) {
		A[i] = i;
	}
}

int pred(int x, int a[], int min, int max)
{
	//cout << min << "." << max << endl;
	int mid = min + ((max - min) / 2);

	if (a[mid] == x || (max - min) == 1 || (max - min) == 0)
	{
		return a[mid];
	} else if (a[mid] > x)
	{
		return pred(x, a, min, mid);
	} else if (a[mid] < x)
	{
		return pred(x, a, mid, max);
	}
}

//int pred(int x)
//{
	//int i = N/2;
	//int level = 4;

	//bool cont = true;

	//while (cont)
	//{
		//cout << i << endl;
		//if (level <= N) {
			//if (A[i] == x) {
				//cont = false;
			//} else if (A[i] < x) {
				//i += N/level;
				//level *= 2;
			//} else if (A[i] > x) {
				//i -= N/level;
				//level *= 2;
			//}
		//} else {
			//if (A[i] <= x) {
				//cont = false;
			//} else {
				//i -= 1;
				//if (i < 0) {
					//return -1;
				//}
			//}
		//}
	//}

	//return A[i];
//}

int main()
{

	init();

	for (int i = 0; i < 1000; i++)
	{
		clock_t start, end;

		start = clock();

		int p = pred(rand() % N, A, 0, N);

		end = clock();

		double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
		cout << p << " time: " << time << endl;
	}
}
