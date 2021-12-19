#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

const int MATRIX_SIZE = 5;

void printMatrix(int** matrix, int size);
int** generateMartix(int size);
void numberPositons(int** matrix, int size);
int firstRule(int** matrix, int size, int x, int y);
int secondRule(int** matrix, int size, int x, int y);
int thirdRule(int** matrix, int size, int x, int y);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int** matrix = generateMartix(MATRIX_SIZE);

	printMatrix(matrix, MATRIX_SIZE);
	cout << "\n";

	numberPositons(matrix, MATRIX_SIZE);

	printMatrix(matrix, MATRIX_SIZE);


}

void printMatrix(int** matrix, int size) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int** generateMartix(int size) {
	//Create dynamic matrix
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	//fill matrix with random numbers from 1 to 6
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 5 + 1;
		}
	}

	return matrix;
}

void numberPositons(int** matrix, int size) {
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			//get number
			int number = matrix[i][j];

			//if it doesnt equals 1,get next number
			if (number != 1) {
				continue;
			}

			//it it equals 1, use first rule
			int newNumber = firstRule(matrix, size, i, j);

			//if we can use first rule, write new num in position
			if (newNumber != 1) {
				matrix[i][j] = newNumber;
				continue;
			}

			//use second rule
			newNumber = secondRule(matrix, size, i, j);
			if (newNumber != 1) {
				matrix[i][j] = newNumber;
				continue;
			}

			//use third rule
			newNumber = thirdRule(matrix, size, i, j);
			if (newNumber != 1) {
				matrix[i][j] = newNumber;
				continue;
			}

			if (newNumber == 1) {
			}
		}
	}

}

int firstRule(int** matrix, int size, int x, int y) {
	if ((x + 3 < size) && matrix[x + 3][y] != 1) {
		return matrix[x + 3][y];
	}

	if ((x - 3 > 0) && matrix[x - 3][y] != 1) {
		return matrix[x - 3][y];
	}

	return 1;
}

int secondRule(int** matrix, int size, int x, int y) {
	for (int j = 0; j < size; j++) {
		if (j == 2) continue;

		if (matrix[x][j] != 1) {
			return matrix[x][j];
		}
	}

	return 1;
}

int thirdRule(int** matrix, int size, int x, int y)
{
	if (x + 2 < size && y + 2 < size && matrix[x + 2][y + 2] != 1) {
		return matrix[x + 2][y + 2];
	}

	if (x - 2 > 0 && y + 2 < size && matrix[x - 2][y + 2] != 1) {
		return matrix[x - 2][y + 2];
	}

	if (x + 2 < size && y - 2 > 0 && matrix[x + 2][y - 2] != 1) {
		return matrix[x + 2][y - 2];
	}

	if (x - 2 > 0 && y - 2 > 0 && matrix[x - 2][y - 2] != 1) {
		return matrix[x - 2][y - 2];
	}

	return 1;
}