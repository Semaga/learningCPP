#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void FindUp( double** mass, const int &dimen, 
	int &position_yMax, int &position_xMax){
	cout<< "FindUp started\n";
	double max_value=0;
	for(int i= 0; i< dimen; ++i){
		for(int j=i+1; j< dimen; ++j){
			if(max_value< mass[i][j]){
				position_yMax= i;
				position_xMax= j;
				max_value= mass[i][j];
			}
		}
	}
	cout<< "Max_value: "<< max_value<< "\tposition_x: "
			<< position_xMax<< "\tposition_y: "<< position_yMax<< endl;
	cout<< "FindUp finished\n";
}


void FindDown( double** mass, const int &dimen,	
	int &position_yMin, int &position_xMin){
	cout<< "FindDown started\n";
	double min_value=mass[1][0];
	for(int i= dimen; i> 0; --i){
		for(int j=i+1; j< dimen; ++j){
			if(min_value> mass[i][j]){
				position_yMin= i;
				position_xMin= j;
				min_value= mass[i][j];
			}
		}
	}
	cout<< "min_value: "<< min_value<< "\tposition_x: "
			<< position_xMin<< "\tposition_y: "<< position_yMin<< endl;
	cout<< "FindDown finished\n";
}

int main(){
	srand(0);

	int dimen;
	cout << "Введите размерность - "; cin>> dimen;
	cout << endl;

	/*Создаем массив используя днамическую память*/
	double **mass= new double *[dimen];
	for(int i= 0; i< dimen; ++i){
		mass[i]= new double [dimen];
	}
	
	/*	заполняем и выводим массив*/
	for(int i= 0; i< dimen; ++i){
		for(int j= 0; j< dimen; ++j){
			mass[i][j]= rand()%1000;
			cout<<setw(2) << mass[i][j]<< ' ';
		}
		cout<< endl;
	}

	int position_yMax,position_yMin, position_xMax, position_xMin;
	FindUp(mass, dimen, position_yMax, position_xMax);
	FindDown(mass, dimen, position_yMin, position_xMin);
	
	swap(mass[position_yMin][position_xMin], mass[position_yMax][position_xMax]);
	/*освобождаем память*/
	cout<< "\n\nafter swap\n";
	for(int i= 0; i< dimen; ++i){
		for(int j= 0; j< dimen; ++j){
			cout<< setw(2)  << mass[i][j]<< ' ';
		}
		cout<< endl;
	}

	for(int i= 0; i< dimen;++i){
		delete []mass[i];
	}

	return 0;
}


