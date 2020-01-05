//Try to calculate electric field of some electric charges

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class ChargeProperties{
public:
	ChargeProperties();
	void set_position_x(double &x){
		position_x = x;
	}
	void set_position_y(double &y){
		position_y = y;
	}
	void set_charge(double &harge){
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

class SubstrateProperties{
public:
	SubstrateProperties();
	void set_leght_x(double &lenght_x){
		lenght_x = lenght_x;
	}
	void set_leght_y(double &lenght_y){
		lenght_y = lenght_y;
	}
	void set_dimnension(int &dimension){
		dimension = dimension;
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

	~SubstrateProperties();
private:
	double lenght_x;
	double lenght_y;
	int dimension;
};

template <typename T>
void WriteVectorToFile(vector <vector <T> > &v){
	ofstream fout("output.txt");
	if(fout){
		cout << "Output file is open ..." << endl;
		for(int i = 0; i != v.size(); i++){
			for(int j = 0; j != v[i].size(); j++){
				fout << v[i][j] << ' ';
			}
		}
		fout.close();
		cout<< "Output file was closed." << endl;
	}else
		cout << "Error file output.txt not found" << endl;
	
}

int main(){
	int dimension = 100;
	//Set dimenstions of unit's part
	double lenght_x = 5.0, lenght_y = 5.0;
	// set lenght both side our cell
	double charge = 1.0;
	//put unit charge
	//in left-upper connor;
	double start_position_x = 0.1;
	double start_position_y = 0.1;
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
	WriteVectorToFile(data);


}