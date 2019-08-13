#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class CppStudio{
	private:
		int day;
		int month;
		int year;

	public:
		CppStudio(int date_day, int date_month, int date_year){
			setDate(date_day, date_month, date_year); // вызов функции установки даты
		}
		void message(){
			std::cout << "\nwebsite: cppstudio.comntheme: Classes and Objects in C ++\n";
		}
		void setDate(int date_day, int date_month, int date_year){
			day   = date_day; // инициализация день
			month = date_month; // инициализация месяц
			year  = date_year; // инициализация год
		}	
		void getDate(){
			std::cout << "\nnamespacedate: " << day << "." << month << "." << 
			year << std::endl;
		}

		~CppStudio(){
			std::cout<< "\n\tУдален класс CppStudio\n\n";
		}

	};

class Students {
	public:
	Students(){
		std::cout<< "\tClass \'Students\' was maked"<< std::endl;
	}
	// Деструктор
	~Students(){
		std::cout << "\tMemory has been cleaned. Good bye." << std::endl;
	}
};

class Animals{
	private:
		std::string Name;
		std::string Breed;
		int Sex;
		int Quantoty;	
		double Prise;

	public:
		Animals(){
			std::cout<< "\tКонструктор класса создан\n";			
		}

		Animals(const Animals& Objects){
			std::cout<< "\tКонструктор копирования создан\n";
		}

		~Animals(){
			std::cout<< "\tДеструктор класса\n";
		}

		void set_ALL(const std::string& info_Name,const std::string& info_Breed,
		 const int& info_sex, const int& info_Quantoty,
		  const double &info_Prise){
			Name     = info_Name;
			Sex      = info_sex;
			Quantoty = info_Quantoty;
			Breed    = info_Breed;
			Prise    = info_Prise;
		}

		void getIfoAll(int check= 0){
			int distance= 10;
			std::cout<< std::fixed << std::setprecision(2);
			// std::cout<< std::setfill('.');
			// std::cout<< std::left;
			if (check== 0){
				std::cout << std::setw(distance) << "Name"     << ' ' 
									<< std::setw(distance) << "Sex"      << ' ' 
									<< std::setw(distance) << "Quantoty" << ' ' 
									<< std::setw(distance) << "Breed"    << ' '
									<< std::setw(distance) <<  "Prise"   << std::endl;
			}
				std::cout << std::setw(distance) << Name       << ' ' 
									<< std::setw(distance) << Sex        << ' ' 
									<< std::setw(distance) << Quantoty   << ' ' 
									<< std::setw(distance) << Breed      << ' '  
									<< std::setw(distance) << Prise      << std::endl;
			
		}

};