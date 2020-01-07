#include "FUNC.h"

template <typename T>
void WriteVectorToFile(std::vector <std::vector <T> > &v, 
	std::vector <CHR_PRP> &Charge, SUB_PRP &Substrate){
	std::ofstream fout("output.txt");
	if(fout){
		std::cout << "Output file is open ..." << std::endl;
		Substrate.WriteDataToFile(fout);
		for(auto &i:Charge){
			i.WriteDataToFile(fout);
		} 
		// Charge.WriteDataToFile(fout);
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