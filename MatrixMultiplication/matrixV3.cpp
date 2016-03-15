#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int M = 100;
int N = 100;
int P = 100;

int MAX = 10;
int MAX_N = 1000;
int MAX_M = 1000;
int MAX_P = 1000;

vector<vector<int> > A;
vector<vector<int> > B;

int init()
{
	vector<vector<int> > a(M, vector<int>(N, 0));
	vector<vector<int> > b(N, vector<int>(P, 0));

	A = a;
	B = b;
	//A.reserve(m);
	//for (int i = 0; i < m; i++) {
		//A[i].reserve(n);
	//}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = rand() % MAX;
		}
	}

	//B.reserve(n);
	//for (int i = 0; i < n; i++) {
		//B[i].reserve(p);
	//}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P; j++) {
			B[i][j] = rand() % MAX;
		}
	}
}

int printMatrix(vector<vector<int> > v)
{
	//cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << "#";
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j] << ", ";
		}
		cout << endl;
	}
}

vector<vector<int> > multiplyMatrix(int ms, int me, int ns, int ne, int ps, int pe)
{
	vector<vector<int> > C(M, vector<int>(P, 0));

	int n = ne - ns;
	int m = me - ms;
	int p = pe - ps;

	if (n <= 1 && m <= 1 && p <= 1)
	{
		C[ms][ps] = A[ms][ns] * B[ns][ps];
		//cout << "# TEST" << endl;
		return C;
	} else if (n >= max(m, p))
	{
		int n1 = n/2;

		vector<vector<int> > c1 = multiplyMatrix(ms, me, ns, n1+ns, ps, pe);
		vector<vector<int> > c2 = multiplyMatrix(ms, me, n1+ns, ne, ps, pe);

		for (int i = ms; i < me; i++) {
			for (int j = ps; j < pe; j++) {
				C[i][j] = c1[i][j] + c2[i][j];
			}
		}

		return C;
	} else if (m >= max(n, p))
	{
		int m1 = m/2;

		vector<vector<int> > c1 = multiplyMatrix(ms, m1+ms, ns, ne, ps, pe);
		vector<vector<int> > c2 = multiplyMatrix(m1+ms, me, ns, ne, ps, pe);

		for (int j = ps; j < pe; j++) {
			for (int i = ms; i < m1+ms; i++) {
				C[i][j] = c1[i][j];
			}
			for (int i = m1+ms; i < me; i++) {
				C[i][j] = c2[i][j];
			}
		}

		return C;

	} else
	{
		int p1 = p/2;

		vector<vector<int> > c1 = multiplyMatrix(ms, me, ns, ne, ps, p1+ps);
		vector<vector<int> > c2 = multiplyMatrix(ms, me, ns, ne, p1+ps, pe);

		for (int i = ms; i < me; i++) {
			for (int j = ps; j < p1+ps; j++) {
				C[i][j] = c1[i][j];
			}
			for (int j = p1+ps; j < pe; j++) {
				C[i][j] = c2[i][j];
			}
		}

		return C;

	}

	return C;
}


int testConstantMNP()
{
	init();
	printMatrix(A);
	cout << "#=====" << endl;
	printMatrix(B);

	cout << "#=========" << endl;
	clock_t start, end;
	start = clock();
	vector<vector<int> > C = multiplyMatrix(0, M, 0, N, 0, P);
	end = clock();
	printMatrix(C);

	double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
	cout << N << " " << M << " " << P << " " << time << endl;
}

int testRisingMNP()
{
	for (int n_1 = 1; n_1 < MAX_N; n_1+=100) {
		for (int m_1 = 1; m_1 < MAX_M; m_1+=100) {
			for (int p_1 = 1; p_1 < MAX_P; p_1+=100) {
				N = n_1;
				M = m_1;
				P = p_1;

				testConstantMNP();
			}
		}
	}
}


int main()
{
	//cout << "TEST" << endl;
	testConstantMNP();
	//testRisingMNP();
}
