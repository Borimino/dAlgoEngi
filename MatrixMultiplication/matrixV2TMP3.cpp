#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int m = 201;
int n = 201;
int p = 201;

int MAX = 10;
int MAX_N = 300;
int MAX_M = 300;
int MAX_P = 300;

vector<vector<int> > A;
vector<vector<int> > B;

int init()
{
	vector<vector<int> > a(m, vector<int>(n, 0));
	vector<vector<int> > b(n, vector<int>(p, 0));

	A = a;
	B = b;
	//A.reserve(m);
	//for (int i = 0; i < m; i++) {
		//A[i].reserve(n);
	//}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = rand() % MAX;
		}
	}

	//B.reserve(n);
	//for (int i = 0; i < n; i++) {
		//B[i].reserve(p);
	//}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
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

vector<vector<int> > multiplyMatrix(vector<vector<int> > a, vector<vector<int> > b, int m, int n, int p)
{
	//cout << "#" << n << " " << m << " " << p << endl;
	vector<vector<int> > C(m, vector<int>(p, 0));

	if (n == 1 && m == 1 && p == 1)
	{
		C[0][0] = a[0][0] * b[0][0];
		//cout << "# " << C[0][0] << endl;
		return C;
	} else if (n >= max(m, p))
	{
		int n1 = n/2;
		int n2 = n - n1;

		vector<vector<int> > a1(m, vector<int>(n1, 0));
		vector<vector<int> > a2(m, vector<int>(n2, 0));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n1; j++) {
				a1[i][j] = a[i][j];
			}
			for (int j = 0; j < n2; j++) {
				a2[i][j] = a[i][j+n1];
			}
		}

		vector<vector<int> > b1(n1, vector<int>(p, 0));
		vector<vector<int> > b2(n2, vector<int>(p, 0));

		for (int j = 0; j < p; j++) {
			for (int i = 0; i < n1; i++) {
				b1[i][j] = b[i][j];
			}
			for (int i = 0; i < n2; i++) {
				b2[i][j] = b[i+n1][j];
			}
		}

		//cout << "#" << n1 << endl;
		//cout << "#" << n2 << endl;

		vector<vector<int> > c1 = multiplyMatrix(a1, b1, m, n1, p);
		//cout << "#" << "TEST" << endl;
		vector<vector<int> > c2 = multiplyMatrix(a2, b2, m, n2, p);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				C[i][j] = c1[i][j] + c2[i][j];
			}
		}

		return C;
	} else if (m >= max(n, p))
	{
		int m1 = m/2;
		int m2 = m - m1;
		vector<vector<int> > a1(m1, vector<int>(n, 0));
		vector<vector<int> > a2(m2, vector<int>(n, 0));

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m1; i++) {
				a1[i][j] = a[i][j];
			}
			for (int i = 0; i < m2; i++) {
				a2[i][j] = a[i+m1][j];
			}
		}

		vector<vector<int> > c1 = multiplyMatrix(a1, b, m1, n, p);
		vector<vector<int> > c2 = multiplyMatrix(a2, b, m2, n, p);

		for (int j = 0; j < p; j++) {
			for (int i = 0; i < m1; i++) {
				C[i][j] = c1[i][j];
			}
			for (int i = 0; i < m2; i++) {
				C[i+m1][j] = c2[i][j];
			}
		}

		return C;

	} else
	{
		int p1 = p/2;
		int p2 = p - p1;
		vector<vector<int> > b1(n, vector<int>(p1, 0));
		vector<vector<int> > b2(n, vector<int>(p2, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p1; j++) {
				b1[i][j] = b[i][j];
			}
			for (int j = 0; j < p2; j++) {
				b2[i][j] = b[i][j+p1];
			}
		}

		vector<vector<int> > c1 = multiplyMatrix(a, b1, m, n, p1);
		vector<vector<int> > c2 = multiplyMatrix(a, b2, m, n, p2);

		//cout << "#" << n << "-" << m << "-" << p << "-" << p1 << "-" << p2 << endl;
		for (int i = 0; i < m; i++) {
			//cout << "#" << i << endl;
			for (int j = 0; j < p1; j++) {
				C[i][j] = c1[i][j];
				//cout << "# " << j << endl;
			}
			for (int j = 0; j < p2; j++) {
				C[i][j+p1] = c2[i][j];
				//cout << "# " << j << endl;
			}
			//cout << "#" << i << endl;
		}

		//cout << "#" << "TEST2" << endl;
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
	vector<vector<int> > C = multiplyMatrix(A, B, m, n, p);
	end = clock();
	printMatrix(C);

	double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
	cout << n << " " << m << " " << p << " " << time << endl;
}

int testRisingMNP()
{
	for (int n_1 = 1; n_1 < MAX_N; n_1+=30) {
		for (int m_1 = 1; m_1 < MAX_M; m_1+=30) {
			for (int p_1 = 1; p_1 < MAX_P; p_1+=30) {
				n = n_1;
				m = m_1;
				p = p_1;

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
