#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int m = 900;
int n = 900;
int p = 900;

int MAX = 10;
int MAX_N = 5000;
int MAX_M = 5000;
int MAX_P = 5000;

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

vector<vector<int> > multiplyMatrix(vector<vector<int> > a, vector<vector<int> > b)
{
	vector<vector<int> > C(m, vector<int>(p, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += a[i][k] * b[k][j];
			}
			C[i][j] = sum;
		}
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
	vector<vector<int> > C = multiplyMatrix(A, B);
	end = clock();
	printMatrix(C);

	double time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
	cout << n << " " << m << " " << p << " " << time << " " << n*m+n*p << endl;
}

int testRisingMNP()
{
	for (int n_1 = 1; n_1 < MAX_N; n_1+=1000) {
		for (int m_1 = 1; m_1 < MAX_M; m_1+=1000) {
			for (int p_1 = 1; p_1 < MAX_P; p_1+=1000) {
	//for (int n_1 = 1; n_1 < MAX_N; n_1*=2) {
		//for (int m_1 = 1; m_1 < MAX_M; m_1*=2) {
			//for (int p_1 = 1; p_1 < MAX_P; p_1*=2) {
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
