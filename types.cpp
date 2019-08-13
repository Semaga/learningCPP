#include <iostream>
#include <string>
#include <vector>
#include <map>  //словари
using namespace std;

struct Person{
	string name;
	string surname;
	int age;
};

int main(){
	int a= 0;
	double pi= 3.14;
	bool logical_value= true;
	char symbol= 'Z';

	string hw= "Hello, world"; 

	std :: vector<int> nums= {1, 3, 5, 7};
	cout << nums.size() <<"\n";
	cout << "HHH\n";

	map<string, int> name_to_value;
	name_to_value["zeros"]= 0;
	name_to_value["one"]= 1;
	name_to_value["two"]= 2;

	cout<< "Two is "<<name_to_value["two"] <<'\n';
	
	vector<Person> staff;
	staff.push_back({"Ivan","Petrov", 22});

	cout<< '\n' << staff[0].name <<'\n';


	return 0;
}
