#ifndef CHR_PRP_H
#define CHR_PRP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

class CHR_PRP{

private:
	double charge_value;
	double position_x;
	double position_y;

public:
	// ChargeProperties();
	void set_position_x(const double &x);
	void set_position_y(const double &y);
	void set_charge(    const double &charge);

	double get_position_x(){ return position_x;   }
	double get_position_y(){ return position_y;   }
	double get_charge(){     return charge_value; }
	
	void WriteDataToFile(ofstream &fout);

};

#endif