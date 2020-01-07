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

void ReadInputFile(const std::string &InputeFile, SUB_PRP &Substrate, int &NumberOfParticle){
	std::cout << "Try to open inpute file" << std::endl;
	std::ifstream fin(InputeFile);
	std::vector <std::string> s;
	if(fin){

		std::cout << "\tInput file is open" << std::endl;
		std::string line;
		double param;
		int chec;
		getline(fin, line);
		getline(fin, line);
		s = split(line);
		param = stod(s[2]);
		std::cout << "\t\tLenght is equal " << param << std::endl; 
		Substrate.set_lenght_x(param);

		
		getline(fin, line);
		s = split(line);
		param = stod(s[2]);	
		std::cout << "\t\tWildth is equal " << param << std::endl; 
		Substrate.set_lenght_y(param);
		std::cout << "\t\tLenght and wildth of substrate was read ..." << std::endl;

		getline(fin, line);
		getline(fin, line);
		s = split(line);
		chec = stoi(s[2]);	
		std::cout << "\t\tDimenstion is equal " << chec << std::endl; 		
		Substrate.set_dimnension(chec);
		std::cout << "\t\tDimenstion of calculation was read ..." << std::endl;

		getline(fin, line);
		getline(fin, line);
		s = split(line);
		chec = stoi(s[4]);	
		std::cout << "\t\tNumber of particles is equal " << param << std::endl; 
		NumberOfParticle = chec;
		std::cout << "\t\tNumber of particles was read ..." << std::endl;

	}
}

std::vector <std::string> split(std::string & s, char delimeter){
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> tokens;
	while (getline(ss, item, delimeter)){
		tokens.push_back(item);
	}
	return tokens;
}