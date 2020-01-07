#include "CHR_PRP.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

void CHR_PRP::set_position_x(const double &x){
	position_x = x;
}
void CHR_PRP::set_position_y(const double &y){
	position_y = y;
}
void CHR_PRP::set_charge(const  double &charge){
	charge_value = charge;
}

void CHR_PRP::WriteDataToFile(ofstream &fout){
	fout << "Particle parameters:"              << endl;
	fout << "\tPosition_X = "   << position_x   << endl;
	fout << "\tPosition_Y = "   << position_y   << endl;
	fout << "\tCharge_value = " << charge_value << endl;
}
