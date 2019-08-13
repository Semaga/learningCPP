#include <iostream>
#include <string>
#include "clasess.h"
#include <vector>

using namespace std;

main(){

	/*Animals *objAnimals = new Animals;

	string info_Name,info_Breed; 
	int info_sex, info_Quantoty;
	double info_Prise;

	cout << "Введите имя животного: ";
	getline(cin, info_Name);

	cout << "Введите породу животного: ";
	getline(cin, info_Breed);

	cout << "Введите пол животного:(0) - M (1) - Ж :";
	cin  >> info_sex;

	cout << "Введите количество животного: ";
	cin  >> info_Quantoty;

	cout << "Введите цену животного: ";
	cin  >> info_Prise;

	objAnimals-> set_ALL(info_Name, info_Breed, info_sex,info_Quantoty, info_Prise);

	objAnimals-> getIfoAll(1);

	delete objAnimals;*/
	
	vector <Animals> v_objAnimals;

	Animals objAnimals;


	string info_Name,info_Breed; 
	int info_sex, info_Quantoty;
	double info_Prise;

	cout << "Введите имя животного: ";
	getline(cin, info_Name);

	cout << "Введите породу животного: ";
	getline(cin, info_Breed);

	cout << "Введите пол животного:(0) - M (1) - Ж :";
	cin  >> info_sex;

	cout << "Введите количество животного: ";
	cin  >> info_Quantoty;

	cout << "Введите цену животного: ";
	cin  >> info_Prise;

	objAnimals.set_ALL(info_Name, info_Breed, info_sex,info_Quantoty, info_Prise);

	objAnimals.getIfoAll(1);

	v_objAnimals.push_back(objAnimals);

	for( auto &i: v_objAnimals){
		i.getIfoAll(1);
	}

	return 0;
}