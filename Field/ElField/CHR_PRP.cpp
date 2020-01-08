#include "CHR_PRP.h"

void CHR_PRP::set_position_x(     const double &x){
	position_x = x;
}
void CHR_PRP::set_position_y(     const double &y){
	position_y = y;
}
void CHR_PRP::set_charge(         const double &charge){
	charge_value = charge;
}

void CHR_PRP::set_action_force_x( const double &force_x){
	action_force_x = force_x;
}
void CHR_PRP::set_action_force_y( const double &force_y){
	action_force_y = force_y;
}

void CHR_PRP::set_energy(         const double &E){
	energy = E;
}

void CHR_PRP::WriteDataToFile(std::ofstream &fout){
	fout << "Particle parameters:"              << std::endl;
	fout << "\tPosition_X = "   << position_x   << std::endl;
	fout << "\tPosition_Y = "   << position_y   << std::endl;
	fout << "\tCharge_value = " << charge_value << std::endl;
}
