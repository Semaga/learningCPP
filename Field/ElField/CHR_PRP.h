#ifndef CHR_PRP_H
#define CHR_PRP_H

#include <fstream>

class CHR_PRP{

private:
	double charge_value;
	double position_x;
	double position_y;
	double position_z;

	double action_force_x;
	double action_force_y;

	double energy;

public:
	void set_position_x(     const double &x     );
	void set_position_y(     const double &y     );
	void set_position_z(     const double &z     );
	void set_charge(         const double &charge);

	void set_action_force_x( const double &force_x);
	void set_action_force_y( const double &force_y);

	void set_energy(         const double &E);

	double get_position_x(){     return position_x;   }
	double get_position_y(){     return position_y;   }
	double get_position_z(){     return position_z;   }
	double get_charge(){         return charge_value; }
	
	double get_action_force_x(){ return action_force_x;}
	double get_action_force_y(){ return action_force_y;}

	double get_energy(){         return energy;}

  void WriteDataToFile(std::ofstream &fout);


};

#endif