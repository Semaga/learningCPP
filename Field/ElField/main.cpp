//Try to calculate electric field of some electric charges

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ChargeProperties
{
public:
	ChargeProperties();
	void set_position_x(double x){
		position_x = x;
	}
	void set_position_y(double y){
		position_y = y;
	}
	void set_charge(double charge){
		charge_value = charge;
	}

	double get_position_x(){
		return position_x;
	}
	double get_position_y(){
		return position_y;
	}

	double get_charge(){
		return charge_value;
	}

	~ChargeProperties();
private:
	double charge_value;
	double position_x;
	double position_y;
};

int main(){
	int dimension = 100;
	//Set dimenstions of unit's part
	vector <vector <double> > data(dimension, vector<double> (dimension));
	//2D Vector for result of calculation
	//In this vector will put data's modulation
	double charge = 1;
	//put unit charge
	//in center cell 
}