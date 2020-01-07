#include "FUNC.h"


void VectorToZero(std::vector <std::vector <double> >&v){
//Get 2d vector and nullifies them
	for(int i = 0; i != v.size(); i++){
		for(int j = 0; j != v[i].size(); j ++){
			v[i][j] = 0;
		}
	}
}

void WriteVectorToFile(std::vector <std::vector <double> > &v, 
	std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate){
	//Get vectors of result of calculation, ChargeParameters and Substrate parameters 
	std::ofstream fout("output.txt");
	//Make stream to write-file
	if(fout){
		std::cout << "Output file is open ..." << std::endl;
		Substrate.WriteDataToFile(fout);
		//Write information about wubstrate
		for(auto &i:Charge){
		//Write information about charge particles using vector
			i.WriteDataToFile(fout);
		} 
		//Write result of calculation to file
		fout << "Data:" << std::endl;
		for(int i = 0; i != v.size(); i++){
			for(int j = 0; j != v[i].size(); j++){
				fout << v[i][j] << ' ';
			}
		}
		fout << std::endl;
		fout.close();
		std::cout<< "Output file was closed." << std::endl;
	}else
		std::cout << "Error file output.txt not found" << std::endl;
}
