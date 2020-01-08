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
	std::string OutputFile_EFS;
	std::string OutputFile_EFP;
	ReadInputFile("InputFile.txt", substrate, NumberOfParticle, OutputFile_EFS, OutputFile_EFP);

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
	std::vector <std::vector <double> > EFS(dimension, std::vector<double> (dimension));
	WriteMessage("Make vector for writing data of EFS", "main");

	std::vector <std::vector <double> > EFP(dimension, std::vector<double> (dimension));
	WriteMessage("Make vector for writing data of EFS", "main");


	//2D Vector for result of calculation
	//In this vector will put data's modulation of Electric Field Strenght
	 
	double delta_x = lenght_x/dimension;                                                  //fragmentation along x-axes
	double delta_y = lenght_y/dimension;                                                  //fragmentation along y-axes

	//zero the vector
	VectorToZero(EFS);
	WriteMessage("Calculate EFF and write data in vector", "main");

	for(int k = 0; k != Charges.size(); k++){
		double position_x = 0.0, position_y = 0.0, R=0; 
		for(int i = 0; i != EFS.size(); i++){
			for(int j = 0; j != EFS[i].size(); j++){
				position_x = Charges[k].get_position_x() - i*delta_x;
				position_y = Charges[k].get_position_y() - j*delta_y;
				R = (pow(position_x, 2) + pow(position_y,2));
				EFS[i][j] += Charges[k].get_charge()/R;
			}
		}
	}
	WriteMessage("Data of EFF was write in vector", "main");
	WriteVectorToFile(OutputFile_EFS, EFS, Charges, substrate);

	VectorToZero(EFP);
	WriteMessage("Calculate Potantial of EF and write data in vector", "main");
	for(int k = 0; k != Charges.size(); k++){
		double position_x = 0.0, position_y = 0.0, R=0; 
		for(int i = 0; i != EFP.size(); i++){
			for(int j = 0; j != EFP[i].size(); j++){
				position_x = Charges[k].get_position_x() - i*delta_x;
				position_y = Charges[k].get_position_y() - j*delta_y;
				R = sqrt(pow(position_x, 2) + pow(position_y,2));
				EFP[i][j] += Charges[k].get_charge()/R;
			}
		}
	}	
	
	WriteVectorToFile(OutputFile_EFP, EFP, Charges, substrate);

	//Calcaulate forces action to particles

	for(int i = 0; i != Charges.size(); i++){
		//Zeroing components of strenghts action to particle
		double force_x = 0.0, force_y = 0.0, R2 = 0.0, delta_y = 0.0, delta_x = 0.0;

		for(int j = 0; j != Charges.size(); j++){
			if (j != i){
				WriteMessage("Ups, ","CalcForse");
				delta_x = Charges[i].get_position_x() - Charges[j].get_position_x();
				delta_y = Charges[i].get_position_y() - Charges[j].get_position_y();
				R2 = pow(delta_y,2) + pow(delta_x,2);
				force_x += Charges[i].get_charge() * Charges[j].get_charge() * delta_x/ pow(R2,1.5);
				force_y += Charges[i].get_charge() * Charges[j].get_charge() * delta_y/ pow(R2,1.5);
			}
		}
		Charges[i].set_action_force_x(force_x);
		Charges[i].set_action_force_y(force_y);
		WriteMessage("Force was Calculate for "+std::to_string(i)+ "particle","main");
	}

	return 0;
}