#include "FUNC.h"


void VectorToZero(std::vector <std::vector <double> >&v){
//Get 2d vector and nullifies them
	for(int i = 0; i != v.size(); i++){
		for(int j = 0; j != v[i].size(); j ++){
			v[i][j] = 0;
		}
	}
	WriteMessage("Vector Zero","FUNC");
}

void WriteVectorToFile(const std::string &OutputFile,std::vector <std::vector <double> > &v, 
	std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate){
	//Get vectors of result of calculation, ChargeParameters and Substrate parameters 
	std::string s = "Start write the " + OutputFile;
	WriteMessage(s,"WriteVectorToFile");
	std::ofstream fout(OutputFile);
	//Make stream to write-file
	if(fout){
		WriteMessage("Output file "+OutputFile+ " is open ...","FUNC");
		Substrate.WriteDataToFile(fout);
		//Write information about wubstrate
		for(auto &i:Charge){
		//Write information about charge particles using vector
			i.WriteDataToFile(fout);
		} 
		//Write result of calculation to file
		WriteMessage("Write date to file","FUNC");
		fout << "Data:" << std::endl;
		for(int i = 0; i != v.size(); i++){
			for(int j = 0; j != v[i].size(); j++){
				fout << v[i][j] << ' ';
			}
		}
		fout << std::endl;
		fout.close();
		WriteMessage("File "+OutputFile+" was closed.","FUNC");
	}else
		WriteMessage("Error file "+OutputFile+" not found","FUNC");
}

void ReadInputFile(const std::string &InputeFile, SUB_PRP &Substrate, int &NumberOfParticle,
  std::string &OutputFile_EFS, std::string &OutputFile_EFP){
	WriteMessage("Try to open inpute file","ReadInputFile");	
	std::cout << "" << std::endl;
	std::ifstream fin(InputeFile);
	std::vector <std::string> s;
	if(fin){
		WriteMessage("Input file is open","ReadInputFile");
		std::string line;
		double param;
		int chec;
		getline(fin, line);
		getline(fin, line);
		s = split(line);
		param = stod(s[2]);
		Substrate.set_lenght_x(param);
		
		getline(fin, line);
		s = split(line);
		param = stod(s[2]);	
		Substrate.set_lenght_y(param);
		WriteMessage("\t\tLenght and wildth of substrate was read ...","ReadInputFile");

		getline(fin, line);
		getline(fin, line);
		s = split(line);
		chec = stoi(s[2]);	
		Substrate.set_dimnension(chec);
		WriteMessage("\t\tDimenstion of calculation was read ...","ReadInputFile");

		getline(fin, line);
		getline(fin, line);
		s = split(line);
		chec = stoi(s[4]);	
		WriteMessage("\t\tNumber of particles is equal ", "ReadInputFile");
		NumberOfParticle = chec;
		WriteMessage("\t\tNumber of particles was read ...", "ReadInputFile");

		getline(fin, line);
		getline(fin, line);
		s = split(line);
		OutputFile_EFS = s[2];
		WriteMessage("\t\tRead name of output file with EFS-data: "+OutputFile_EFS, "ReadInputFile");

		getline(fin, line);
		s = split(line);
		OutputFile_EFP = s[2];
		WriteMessage("\t\tRead name of output file with EFP-data: "+OutputFile_EFP, "ReadInputFile");
		

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

void WriteMessage(const std::string &s, const std:: string &PositionFile){
	std::cout << "\t####" << std::endl;
	std::cout << '\t' << "Message from " << PositionFile <<" function :\t" << s << std::endl;
}
