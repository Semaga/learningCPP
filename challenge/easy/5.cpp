#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>


using namespace std;



int main(){
 	
	int width, hight;

	cout<< "Введите количество cтрок матрицы: "; cin>> hight;
	cout<< "Введите количество столбцов матрицы: "; cin>> width;

	double matrix[hight][width];
	vector <double> vec(width);
	for (int i = 0; i < hight; ++i){
		for (int j = 0; j < width; ++j){
			cout<< "\nВведите элемент matrix["<< i<<"," <<j <<"] матрицы: "; cin>>matrix[i][j] ;
		}
		cout<< endl;
		/* code */
	}
	cout<< "Введите количество столбцов матрицы: "; cin>> width;


 	return 0;
}	