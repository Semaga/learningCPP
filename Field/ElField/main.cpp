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


int main(int argc, char const *argv[]){
	SUB_PRP substrate;
	//Set paramaters of cell wildth and lenght, fragmentation
	int NumberOfParticle;
	ReadInputFile("InputFile.txt", substrate, NumberOfParticle);

	//Put data of substrate to variables
	int dimension = substrate.get_dimension();
	double lenght_x = substrate.get_lenght_x();
	double lenght_y = substrate.get_lenght_y();
	
	//make vector with Charges properties
	std::vector<CHR_PRP> Charges(NumberOfParticle);
	WriteMessage("Start to write particles's position", "main");
	srand (time(NULL));
	for (int i = 0; i != Charges.size(); i++){
		Charges[i].set_charge(1);                                                           //set unit charhe
		double posx = 0;
		posx = lenght_x / RAND_MAX * rand();
		if (posx >= lenght_x){
			posx =  2*lenght_x - posx;
		}
		Charges[i].set_position_x(posx);                                                    //set position in centimeters
		posx = lenght_y / RAND_MAX * rand();
		if (posx >= lenght_y){
			posx =  2*lenght_y - posx;
		}
		Charges[i].set_position_y(lenght_y / RAND_MAX * rand());                            //set position in centimeters 		
	}	
	WriteMessage("Particles's position was write", "main");
	std::vector <std::vector <double> > data(dimension, std::vector<double> (dimension));
	WriteMessage("Make vector for writing data", "main");
	//2D Vector for result of calculation
	//In this vector will put data's modulation
	 
	double delta_x = lenght_x/dimension;                                                  //fragmentation along x-axes
	double delta_y = lenght_y/dimension;                                                  //fragmentation along y-axes

	//zero the vector
	// VectorToZero(data);
	WriteMessage("Calculate and write data in vector", "main");

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
	WriteMessage("Data was write in vector", "main");

	WriteVectorToFile(data, Charges, substrate);
	return 0;
}