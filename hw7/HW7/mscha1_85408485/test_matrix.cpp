#include <iostream>
#include "Matrix.h"
#include "Exception.h"

using namespace std;

template
    <typename T>
void fillMatrix(Matrix <T> & m){
    int i, j;

    for (i = 0; i < m.numRows(); i++)
	m[i][0] = T();
    for (j = 0; j < m.numCols(); j++)
	m[0][j];
    for (i = 1; i < m.numRows(); i++){
	for (j = 1; j < m.numCols(); j++){
	    m[i][j] = T(i * j);
	}
    }
}

void test_int_matrix(){
    Matrix <int> m(10, 5);
    fillMatrix(m);
    cout << m;
}

void test_double_matrix(){
    Matrix <double> M(8, 10);
    fillMatrix(M);
    cout << M;
}

void generate_exception(Matrix <double> & m){
    for (int i = 0; i < 666; i++){
	m[i][i] = 10;
    }
}

void test_double_matrix_exceptions(){
    try 
    {
	cout << "Starting...\n";
        Matrix <double> M(8, 10);
        fillMatrix(M);
        cout << M;
        generate_exception(M);
        cout << "Done\n";
    }
    catch (IndexOutOfBoundsException & e)
    {
        cout << "Index out of bounds \n";
    }
}

int main(){
    for (int i = 0; i < 3; ++i){
        test_int_matrix();
        test_double_matrix();
        test_double_matrix_exceptions();
    }
    return 0;
}
