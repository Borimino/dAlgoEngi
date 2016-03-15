#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int M = 2;
int N = 2;
int P = 2;

int MAX = 10;
int MAX_N = 5000;
int MAX_M = 5000;
int MAX_P = 5000;

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
	int n = ne - ns;
	int m = me - ms;
	int p = pe - ps;


	if (n <= 1 && m <= 1 && p <= 1)
	{
		vector<vector<int> > C(m, vector<int>(p, 0));

		C[0][0] = A[ms][ns] * B[ns][ps];
		//cout << "# TEST" << endl;
		return C;
	} else if (n >= max(m, p))
	{
		//vector<vector<int> > C(m, vector<int>(p, 0));

		int n1 = n/2;

		vector<vector<int> > c1 = multiplyMatrix(ms, me, ns, n1+ns, ps, pe);
		vector<vector<int> > c2 = multiplyMatrix(ms, me, n1+ns, ne, ps, pe);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				c1[i][j] = c1[i][j] + c2[i][j];
			}
		}
		//cout << "# TEST1" << endl;

		return c1;
	} else if (m >= max(n, p))
	{
		int m1 = m/2;

		vector<vector<int> > c1 = multiplyMatrix(ms, m1+ms, ns, ne, ps, pe);
		vector<vector<int> > c2 = multiplyMatrix(m1+ms, me, ns, ne, ps, pe);
		
		//cout << "# TEST21" << endl;
		
		c1.resize(m, vector<int>(p, 0));

		//cout << "# TEST22" << endl;
		//cout << c1.size() << endl;
		//cout << m << endl;
		//cout << m1 << endl;
		//cout << c2.size() << endl;
		//cout << p << endl;
		//cout << c1[0].size() << endl;
		//cout << c2[0].size() << endl;

		for (int j = 0; j < p; j++) {
			for (int i = m1; i < m; i++) {
				c1[i][j] = c2[i-m1][j];
			}
		}

		//for (int j = 0; j < p; j++) {
			//for (int i = 0; i < m1; i++) {
				//C[i][j] = c1[i][j];
			//}
			//for (int i = m1; i < m; i++) {
				//C[i][j] = c2[i-m1][j];
			//}
		//}
		//cout << "# TEST2" << endl;

		return c1;

	} else
	{
		vector<vector<int> > C(m, vector<int>(p, 0));

		int p1 = p/2;

		vector<vector<int> > c1 = multiplyMatrix(ms, me, ns, ne, ps, p1+ps);
		vector<vector<int> > c2 = multiplyMatrix(ms, me, ns, ne, p1+ps, pe);

		//cout << "# TEST31" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p1; j++) {
				C[i][j] = c1[i][j];
			}
			for (int j = p1; j < p; j++) {
				C[i][j] = c2[i][j-p1];
			}
		}
		//cout << "# TEST3" << endl;

		return C;

	}
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
	for (int n_1 = 1; n_1 < MAX_N; n_1+=1000) {
		for (int m_1 = 1; m_1 < MAX_M; m_1+=1000) {
			for (int p_1 = 1; p_1 < MAX_P; p_1+=1000) {
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
	//testConstantMNP();
	testRisingMNP();
}
