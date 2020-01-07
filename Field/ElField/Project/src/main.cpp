//Try to calculate electric field of some electric charges

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

#include "CHR_PRP.h"
#include "SUB_PRP.h"


template <typename T>
void WriteVectorToFile(vector <vector <T> > &v, 
	vector <CHR_PRP> &Charge, SUB_PRP &Substrate){
	ofstream fout("output.txt");
	if(fout){
		cout << "Output file is open ..." << endl;
		Substrate.WriteDataToFile(fout);
		for(auto &i:Charge){
			i.WriteDataToFile(fout);
		} 
		// Charge.WriteDataToFile(fout);
		fout << "Data:" << endl;
		for(int i = 0; i != v.size(); i++){
			for(int j = 0; j != v[i].size(); j++){
				fout << v[i][j] << ' ';
			}
		}
		fout << endl;
		fout.close();
		cout<< "Output file was closed." << endl;
	}else
		cout << "Error file output.txt not found" << endl;
}

int main(int argc, char const *argv[]){
	SUB_PRP substrate;

	//Set paramaters of cell wildth and lenght, fragmentation
	substrate.set_lenght_x(5.0);  //centimeters
	substrate.set_lenght_y(5.0);  //centimeters
	substrate.set_dimnension(50); 

	//Put data of substrate to variables
	int dimension = substrate.get_dimension();
	double lenght_x = substrate.get_lenght_x();
	double lenght_y = substrate.get_lenght_y();
	
	//make vector with Charges properties
	vector<CHR_PRP> Charges(2);
	srand (time(NULL));

	for (int i = 0; i != Charges.size(); i++){
		Charges[i].set_charge(1);            //set unit charhe
		Charges[i].set_position_x(rand()%5); //set position in centimeters
		Charges[i].set_position_y(rand()%5); //set position in centimeters 		
	}	

	vector <vector <double> > data(dimension, vector<double> (dimension));
	//2D Vector for result of calculation
	//In this vector will put data's modulation
	 
	double delta_x = lenght_x/dimension; //fragmentation along x-axes
	double delta_y = lenght_y/dimension; //fragmentation along y-axes

	//zero the vector
	for(int i = 0; i != data.size(); i++){
		for(int j = 0; j != data[i].size(); j++){
			data[i][j] = 0;
		}
	}

	for(int k = 0; k != Charges.size(); k++){
		double position_x = 0.0, position_y = 0.0, R=0; 
		for(int i = 0; i != data.size(); i++){
			for(int j = 0; j != data[i].size(); j++){
				position_x = Charges[k].get_position_x() - i*delta_x;
				position_y = Charges[k].get_position_y() - j*delta_y;
				R = (pow(position_x, 2) + pow(position_y,2));
				data[i][j] += Charges[k].get_charge()/R;
			}
		}
	}

	WriteVectorToFile(data, Charges, substrate);

	return 0;
}