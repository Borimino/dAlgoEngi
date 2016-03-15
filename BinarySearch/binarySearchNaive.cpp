#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

//const int N=1000000000;
int N = pow(2, 28) - 1;
//const int N=1024*1024;

int* A = new int[N];

void init()
{
	A = new int[N];

	for (int i = 0; i < N; i++) {
		A[i] = i;
	}
}

int pred(int x, int min, int max)
{
	//cout << min << "." << max << endl;
	int mid = min + ((max - min) / 2);

	if (A[mid] == x || (max - min) == 1 || (max - min) == 0)
	{
		return A[mid];
	} else if (A[mid] > x)
	{
		return pred(x, min, mid);
	} else if (A[mid] < x)
	{
		return pred(x, mid, max);
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

	// // Rising
	
	for (int i = 1; i < 29; i++)
	{
		N = pow(2, i) - 1;

		init();

		cout << "# Init done" << endl;

		clock_t start, end;

		for (int j = 0; j < 100; j++)
		{
			start = clock();

			int p = pred(rand() % N, 0, N);

			end = clock();

			double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
			cout << i << " " << j << " time: " << time << " p: " << p << endl;
		}

		delete[] A;
	}


	// // Constant

	//init();

	//cout << "# Init done" << endl;

	//for (int i = 0; i < 100000; i++)
	//{
		//clock_t start, end;

		//start = clock();

		//int p = pred(rand() % N, 0, N);

		//end = clock();

		//double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
		//cout << i << " time: " << time << " p: " << p << endl;

	//}
	//delete[] A;
}
