//Try to calculate electric field of some electric charges

//Import stadardt header files
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <time.h>

//Import own header files
#include "CHR_PRP.h"
#include "SUB_PRP.h"
#include "FUNC.h"

// template <typename T>
// void WriteVectorToFile(std::vector <std::vector <T> > &v, 
// 	std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate){
// 	std::ofstream fout("output.txt");
// 	if(fout){
// 		std::cout << "Output file is open ..." << std::endl;
// 		Substrate.WriteDataToFile(fout);
// 		for(auto &i:Charge){
// 			i.WriteDataToFile(fout);
// 		} 
// 		// Charge.WriteDataToFile(fout);
// 		fout << "Data:" << std::endl;
// 		for(int i = 0; i != v.size(); i++){
// 			for(int j = 0; j != v[i].size(); j++){
// 				fout << v[i][j] << ' ';
// 			}
// 		}
// 		fout << std::endl;
// 		fout.close();
// 		std::cout<< "Output file was closed." << std::endl;
// 	}else
// 		std::cout << "Error file output.txt not found" << std::endl;
// }


int main(int argc, char const *argv[]){
	SUB_PRP substrate;

	//Set paramaters of cell wildth and lenght, fragmentation
	substrate.set_lenght_x(5.0);  //centimeters
	substrate.set_lenght_y(5.0);  //centimeters
	substrate.set_dimnension(100); 

	//Put data of substrate to variables
	int dimension = substrate.get_dimension();
	double lenght_x = substrate.get_lenght_x();
	double lenght_y = substrate.get_lenght_y();
	
	//make vector with Charges properties
	std::vector<CHR_PRP> Charges(10);

	srand (time(NULL));
	for (int i = 0; i != Charges.size(); i++){
		Charges[i].set_charge(1);                //set unit charhe
		Charges[i].set_position_x(lenght_x / RAND_MAX * rand()); //set position in centimeters
		Charges[i].set_position_y(lenght_y / RAND_MAX * rand()); //set position in centimeters 		
	}	

	std::vector <std::vector <double> > data(dimension, std::vector<double> (dimension));
	//2D Vector for result of calculation
	//In this vector will put data's modulation
	 
	double delta_x = lenght_x/dimension; //fragmentation along x-axes
	double delta_y = lenght_y/dimension; //fragmentation along y-axes

	//zero the vector
	// VectorToZero(data);

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