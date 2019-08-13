#include <iostream>

using namespace std;

#include "clasess.h"


int main() {
	CppStudio * objCppStudio = new CppStudio(06,11,1995);

	objCppStudio-> getDate();

	objCppStudio-> message();
	objCppStudio-> setDate(1,2,3);
	objCppStudio-> getDate();

	delete objCppStudio;

	Students *student = new Students;

	delete student;
  return 0;
}