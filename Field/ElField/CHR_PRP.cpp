#include "CHR_PRP.h"

void CHR_PRP::set_position_x(const double &x){
	double put_x;
	if (x < 0 ){
		put_x = 0.5 * lenght_x; 
		position_x = put_x;
	}
	if (x > lenght_x){
		put_x = 0.95 * lenght_x; 
		position_x = put_x;
	}
	position_x = x;
}
void CHR_PRP::set_position_y(const double& y){
	double put_y;
	if (y < 0){
		put_y = 0.5 * lenght_y;
		position_y = put_y;
	}
	if (y > lenght_y){
		put_y = 0.95 * lenght_y; 
		position_y = put_y;
	}
	position_y = y;
}
void CHR_PRP::set_position_z(const double &z){
	position_z = z;
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

double CHR_PRP::get_action_force_x(){ 
	//adding force interaction with walls
	double f = 0.0, x;
	x = position_x;
	f =   - 1000000*(x - lenght_x/2) ;
	f += action_force_x;
	return f;
}

double CHR_PRP::get_action_force_y(){ 
	//adding force interaction with walls
	double f = 0.0, y;
	y = position_y;

	f =   - 1000000*(y - lenght_y/2) ;
	f += action_force_y;
	return f;
}
