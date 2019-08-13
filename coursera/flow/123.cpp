#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int (){
	ifstream input("hello_world.txt");
	string line;
	//getline считывает строку до '\n'
	// if(input.is_open()){
	if(input){

		while(getline(input,line)){
			cout<< line<< endl;
		}
		cout<< "Done\n";
	}
	else{
		cout<< "error\n";
	}
	
	return 0;
}

