//Try to calculate electric field of some electric charges

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class ChargeProperties{
public:
	// ChargeProperties();
	void set_position_x(const double &x){
		position_x = x;
	}
	void set_position_y(const double &y){
		position_y = y;
	}
	void set_charge(const  double &charge){
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
	void WriteDataToFile(ofstream &fout){
		fout << "Particle parameters:"              << endl;
		fout << "\tPosition_X = "   << position_x   << endl;
		fout << "\tPosition_Y = "   << position_y   << endl;
		fout << "\tCharge_value = " << charge_value << endl;
	}
	// ~ChargeProperties();
private:
	double charge_value;
	double position_x;
	double position_y;
};

class SubstrateProperties{
public:
	// SubstrateProperties();
	void set_lenght_x(const  double &x){
		lenght_x = x;
	}
	void set_lenght_y(const double &y){
		lenght_y = y;
	}
	void set_dimnension(const int &d){
		dimension = d;
	}

	double get_lenght_x(){
		return lenght_x;
	}
	double get_lenght_y(){
		return lenght_y;
	}
	int get_dimension(){
		return dimension;
	}

	void WriteDataToFile(ofstream &fout){
		fout << "Substrate parameters:"       << endl;
		fout << "\tLenght_X = "  << lenght_x  << endl;
		fout << "\tLenght_Y = "  << lenght_y  << endl;
		fout << "\tDimension = " << dimension << endl;
	}

	// ~SubstrateProperties();
private:
	double lenght_x;
	double lenght_y;
	int dimension;
};

template <typename T>
void WriteVectorToFile(vector <vector <T> > &v, 
	ChargeProperties &Charge, SubstrateProperties &Substrate){
	ofstream fout("output.txt");
	if(fout){
		cout << "Output file is open ..." << endl;
		Substrate.WriteDataToFile(fout);
		Charge.WriteDataToFile(fout);
		for(int i = 0; i != v.size(); i++){
			for(int j = 0; j != v[i].size(); j++){
				fout << v[i][j] << ' ';
			}
		}
		fout << endl;
		fout.close();
		cout<< "Output file was closed." << endl;
	}else
		cout << "Error file output.txt not found" << endl;
}

int main(){
	SubstrateProperties substrate;
	substrate.set_lenght_x(5.0);
	substrate.set_lenght_y(5.0);
	substrate.set_dimnension(100);

	ChargeProperties charges;
	charges.set_charge(10);
	charges.set_position_x(2.5);
	charges.set_position_y(4);

	int dimension = substrate.get_dimension();
	//Set dimenstions of unit's part
	double lenght_x = substrate.get_lenght_x();
	double lenght_y = substrate.get_lenght_y();
	// set lenght both side our cell
	double charge = charges.get_charge();
	//put unit charge
	//in left-upper connor;
	double start_position_x = charges.get_position_x();
	double start_position_y = charges.get_position_y();
	//define initial position
	double position_x = 0.0, position_y = 0.0; 

	vector <vector <double> > data(dimension, vector<double> (dimension));
	//2D Vector for result of calculation
	//In this vector will put data's modulation
	 
	double delta_x = lenght_x/dimension;
	double delta_y = lenght_y/dimension;

	for(int i = 0; i != data.size(); i++){
		for(int j = 0; j != data[i].size(); j++){
			position_x = start_position_x - i*delta_x;
			position_y = start_position_y - j*delta_y;
			data[i][j] = charge/(pow(position_x, 2) + pow(position_y,2));
		}
	}
	WriteVectorToFile(data, charges, substrate);


}