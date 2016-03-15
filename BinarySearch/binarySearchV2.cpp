#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
//#include <array>

using namespace std;

//const int N=1000000000;
//const int N=100000000;
//const int N = 1073741823;
//const int N = pow(2, 25) - 1;
//const int N = pow(2, 28) - 1;
//const int N = 1024*1024*16;
//const int N = 1024*1024*2;
//const int N = 1024*2047;
//const int N = 1024*2046 + 1;
//const int N = 1024*2046;
//const int N = 1024*2046;
//const int N = 1024*1025;
//const int N = 1024*1024*1;
//const int N = 128;
//const int N = 7;
int N = pow(2, 28) - 1;

//int A[N];
//int b[N];
int* A = new int[N];
int* b = new int[N];
//array<int, N> A;
//array<int, N> b;
int i = 0;

class Node {
public:
    int start;
    int end;
};

void BFSend()
{
	for (int i = 0; i < N; i++)
	{
		A[i] = b[i];
		//cout << A[i] << " ";
	}
}

void BFSiterate(int start, int end)
{
	//cout << "#TEST " << start << "," << end << endl;
	queue<Node> que;
	Node n;
	n.start = start;
	n.end = end;
	que.push(n);

	while (i < N)
	{

		//if (N >= 8 && i % (N/8) == 0)
		//{
			//cout << i << endl;
		//}

		if (i == pow(2, 28))
		{
			cout << i << endl;
		}

		n = que.front();
		que.pop();
		//cout << "TEST " << n.start << "," << n.end << endl;
		int mid = n.start + (n.end - n.start) / 2;
		b[i] = A[mid];
		i++;
		if (n.start <= mid-1)
		{
			Node t;
			t.start = n.start;
			t.end = mid-1;
			que.push(t);
			//BFSiterate(start, mid-1);
		}
		if (mid+1 <= n.end)
		{
			Node t;
			t.start = mid+1;
			t.end = n.end;
			que.push(t);
			//BFSiterate(mid+1, end);
		}
	}
}

//void BFSiterate(int start, int end) {
	//cout << "TEST" << endl;
    //queue<Node>que;
    //Node n;
    //n.start = start;
    //n.end = end;
    //que.push(n);

	//int b[N];
	//int i = 0;


    //while(!que.empty()) {
        //n = que.front();
        //que.pop();
        //int mid = n.start + (n.end - n.start) / 2;

		////if (mid >= N)
		////{
			////cout << "ERROR" << endl;
		////}

		////cout << A[mid] << endl;
		//b[i] = A[mid];
		//i++;
		////if (i >= N)
		////{
			////cout << "ERROR" << endl;
		////}

        //Node x;
        //x.start = n.start;
        //x.end = mid-1;
        //if (x.start<=x.end)
            //que.push(x); //left

        //x.start = mid+1;
        //x.end = n.end;
        //if (x.start<=x.end)
            //que.push(x); //right
    //}

	//for (int i = 0; i < N; i++) {
		//A[i] = b[i];
	//}
//}

void init()
{
	A = new int[N];
	b = new int[N];
	i = 0;

	for (int i = 0; i < N; i++) {
		A[i] = i;
	}

	cout << "#TEST" << endl;
	BFSiterate(0, N-1);
	BFSend();
}

void deinit()
{
	delete[] A;
	delete[] b;
}

int pred(int x, int i)
{
	//cout << "# Pred" << endl;

	if (i >= N)
	{
		return -1;
	}

	//cout << x << endl;
	//cout << i << endl;
	//cout << a[i] << endl;
	//cout << endl;

	if (A[i] == x)
	{
		//cout << "==" << endl;
		return A[i];
	} else if (A[i] < x)
	{
		//cout << ">" << endl;
		return pred(x, ((i+1)*2+1)-1);
	} else if (A[i] > x)
	{
		//cout << "<" << endl;
		return pred(x, ((i+1)*2)-1);
	}
}

//int pred(int x, int a[], int i)
//{
	//if (i >= N)
	//{
		//return -1;
	//}

	////cout << x << endl;
	////cout << i << endl;
	////cout << a[i] << endl;
	////cout << endl;

	//if (a[i] == x)
	//{
		////cout << "==" << endl;
		//return a[i];
	//} else if (a[i] < x)
	//{
		////cout << ">" << endl;
		//return pred(x, a, ((i+1)*2+1)-1);
	//} else if (a[i] > x)
	//{
		////cout << "<" << endl;
		//return pred(x, a, ((i+1)*2)-1);
	//}
//}

//int pred(int x, int A[], int min, int max)
//{
	////cout << min << "." << max << endl;
	//int mid = min + ((max - min) / 2);

	//if (A[mid] == x || (max - min) == 1 || (max - min) == 0)
	//{
		//return A[mid];
	//} else if (A[mid] > x)
	//{
		//return pred(x, a, min, mid);
	//} else if (A[mid] < x)
	//{
		//return pred(x, a, mid, max);
	//}
//}

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

void testConstantNRandomGuesses()
{
	init();

	cout << "# Init done" << endl;
	
	for (int i = 0; i < 100000; i++)
	//for (int i = 0; i < 10; i++)
	{
		clock_t start, end;

		start = clock();

		//int p = pred(rand() % N, A, 0, N);
		//int p = pred(rand() % N, A, 0);
		int p = pred(rand() % N, 0);

		end = clock();

		double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
		cout << i << " time: " << time << endl;
	}

	deinit();
}

void testRisingNRandomGuesses()
{
	for (int i = 1; i < 29; i++)
	{
		N = pow(2, i) - 1;

		init();

		cout << "# Init done" << endl;

		clock_t start, end;

		//cout << "#TEST" << endl;
		
		for (int j = 0; j < 100; j++)
		{

			start = clock();

			int target = rand() % N;

			//cout << "#" << target << endl;

			//int p = pred(rand() % N, A, 0);
			int p = pred(target, 0);

			end = clock();

			double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
			cout << i << " " << j << " time: " << time << " p: " << p << endl;

		}

		deinit();
	}
}

int main()
{
	//testConstantNRandomGuesses();
	testRisingNRandomGuesses();
	
	//init();
}
