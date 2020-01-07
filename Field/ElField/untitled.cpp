#include "FUNC.h"



int main(int argc, char const *argv[]){
	int dimension = 10;
	std::vector <std::vector <double> > data(dimension, std::vector<double> (dimension));
	VecorToZero(data);
	return 0;
}