#include <iostream>
#include <vector>
#define matrix vector<vector<int>>
using namespace std;

/* 2 Dimensions Martrix Addition */

matrix new2DMatrix(int rows, int columns) {
	matrix vec(rows, vector<int>(columns, 0));
	return vec;
}

matrix add(matrix A, matrix B) {
	int rows = A.size();
	int columns = A[0].size();
	matrix C = new2DMatrix(rows, columns);

	for (int matRow = 0; matRow < rows; matRow++) {
		for (int matCol = 0; matCol < columns; matCol++) {
			C[matRow][matCol] = A[matRow][matCol] + B[matRow][matCol];
		}
	}

	return C;
}

matrix input2DMatrix(int rows, int columns) {
	matrix A = new2DMatrix(rows, columns);
	for (int matRow = 0; matRow < rows; matRow++) {
		for (int matCol = 0; matCol < columns; matCol++) {
			cout << "Please a value at row " << matRow << " column " << matCol << " : ";
			cin >> A[matRow][matCol];
		}
	}

	return A;
}

void printMatrix(matrix A) {
	for (auto row : A) {
		for (auto val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
}

int main() {
	int m, n;
	cout << "Please Enter number of rows of a martrix : ";
	cin >> m;
	cout << "Please Enter number of columns of a martrix : ";
	cin >> n;
	cout << "\n";
	cout << "--------------1st Matrix-------------" << "\n";
	matrix A = input2DMatrix(m, n);
	cout << "\n";
	cout << "--------------2nd Matrix-------------" << "\n";
	matrix B = input2DMatrix(m, n);
	matrix C = add(A, B);
	cout << "\n";
	cout << "-------------Answer Matrix-----------" << "\n";
	printMatrix(C);
	return 0;
}