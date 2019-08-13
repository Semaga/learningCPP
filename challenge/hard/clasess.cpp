/*#include <iostream>
#include "clasess.h"

using namespace std;

CppStudio::CppStudio(int date_day, int date_month, int date_year){
	setDate(date_day,date_month, date_year);
}

void CppStudio::message(){
	cout<< "Hello world" << endl;
}

void CppStudio::setDate(int date_day, int date_month, int date_year){
	day= date_day;
	month= date_month;
	year= date_year;
	}

void CppStudio::getDate(){
	cout<< "Date: " << day << '/'<< month << '/'<< year << endl;
}*/

#include <iostream>
using namespace std;
// подключаем интерфейс класса к файлу его реализации
#include "clasess.h"
 
CppStudio::CppStudio(int date_day, int date_month, int date_year ) // конструктор класса
{
 setDate(date_day, date_month, date_year); // вызов функции установки даты
}
 
void CppStudio::message() // функция (метод класса) выводящая сообщение на экран
{
 cout << "nwebsite: cppstudio.comntheme: Classes and Objects in C ++\n";
}
 
void CppStudio::setDate(int date_day, int date_month, int date_year) // установка даты в формате дд.мм.гг
{
 day   = date_day; // инициализация день
 month = date_month; // инициализация месяц
 year  = date_year; // инициализация год
}
 
void CppStudio::getDate() // отобразить текущую дату
{
 cout << "\ndate: " << day << "." << month << "." << year << endl;
}