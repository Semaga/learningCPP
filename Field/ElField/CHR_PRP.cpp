#include "CHR_PRP.h"

void CHR_PRP::set_position_x(const double &x){
	position_x = x;
}
void CHR_PRP::set_position_y(const double &y){
	position_y = y;
}
void CHR_PRP::set_charge(const double &charge){
	charge_value = charge;
}

void CHR_PRP::set_action_force_x( const double &coord_x,
		                              const double &coord_y,
		                              const double &charge ){
	double Fx, dx, dy, R2;
	dx = position_x - coord_x;
	dy = position_y - coord_y;
	R2 = pow((dx),2) + pow((dy),2);
	Fx = charge_value * charge * dx / pow(R2, 1.5);

	action_force_x = Fx;
}
void CHR_PRP::set_action_force_y( const double &coord_x,
		                              const double &coord_y,
		                              const double &charge ){
	double Fy, dx, dy, R2;
	dx = position_x - coord_x;
	dy = position_y - coord_y;
	R2 = pow((dx),2) + pow((dy),2);
	Fy = charge_value * charge * dy / pow(R2, 1.5);

	action_force_y = Fy;
}




void CHR_PRP::WriteDataToFile(std::ofstream &fout){
	fout << "Particle parameters:"              << std::endl;
	fout << "\tPosition_X = "   << position_x   << std::endl;
	fout << "\tPosition_Y = "   << position_y   << std::endl;
	fout << "\tCharge_value = " << charge_value << std::endl;
}
