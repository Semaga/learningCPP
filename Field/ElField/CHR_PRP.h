#ifndef CHR_PRP_H
#define CHR_PRP_H

#include <fstream>
#include <cmath>

class CHR_PRP{

private:
	double charge_value;
	double position_x;
	double position_y;

	double action_force_x;
	double action_force_y;

public:
	void set_position_x(     const double &x     );
	void set_position_y(     const double &y     );
	void set_charge(         const double &charge);

	void set_action_force_x( const double &coord_x,
		                       const double &coord_y,
		                       const double &charge );
	void set_action_force_y( const double &coord_x,
		                       const double &coord_y,
		                       const double &charge );

	void WriteDataToFile(std::ofstream &fout);

	double get_position_x(){    return position_x;   }
	double get_position_y(){    return position_y;   }
	double get_charge(){        return charge_value; }
	
	double get_action_force_x(){return action_force_x;}
	double get_action_force_y(){return action_force_y;}

};

#endif