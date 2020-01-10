#include "CHR_PRP.h"

void CHR_PRP::set_position_x(     const double &x      ){
	if (x < 0){
		position_x = 0.01 * lenght_x;
	}
	else if (x > lenght_x){
		position_x = 0.99 * lenght_x;
	}
	position_x = x;
}
void CHR_PRP::set_position_y(     const double& y      ){
	if (y < 0)
		position_y = 0.01 * lenght_y;
	else if (y > lenght_y)
		position_y = 0.99 * lenght_y;
	else
	position_y = y;
}

void CHR_PRP::set_position_z(     const double &z       ){
	position_z = z;
}
void CHR_PRP::set_charge(         const double &charge  ){
	charge_value = charge;
}

void CHR_PRP::set_action_force_x( const double &force_x ){
	action_force_x = force_x;
}
void CHR_PRP::set_action_force_y( const double &force_y ){
	action_force_y = force_y;
}

void CHR_PRP::set_energy(         const double &E       ){
	energy = E;
}

void CHR_PRP::WriteDataToFile(std::ofstream &fout){
	fout << "Particle parameters:"              << std::endl;
	fout << "\tPosition_X = "   << position_x   << std::endl;
	fout << "\tPosition_Y = "   << position_y   << std::endl;
	fout << "\tCharge_value = " << charge_value << std::endl;
}

double CHR_PRP::get_action_force_x(){ 
	return action_force_x;
}

double CHR_PRP::get_action_force_y(){ 
	return action_force_y;
}
