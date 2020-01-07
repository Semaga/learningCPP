#include "FUNC.h"


void VecorToZero(std::vector <std::vector <double> >&v){
	for(int i = 0; i != v.size(); i++){
		for(int j = 0; j != v[i].size(); j ++){
			v[i][j] = 0;
		}
	}
}

