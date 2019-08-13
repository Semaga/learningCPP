#include <iostream>
#include <vector>

using namespace std;

main(){
	int c = 0;

	vector <int> vec = {999 ,350 ,1206 ,404 ,1130 ,580 ,1045 ,
		863 ,717 ,871 ,1067 ,1223 ,
		933 ,510 ,1201 ,571 ,111 ,642 ,
		577 ,337 ,809 ,284 ,519 ,69 ,
		414 ,1004 ,414 ,877 ,749 ,1185 ,
		347 ,447 ,235 ,252 ,841 ,64 ,823 ,586 ,918 ,239 ,156, 685};


	for( const auto &i: vec){
		c+= i;
	}

	cout << "c = " << c << endl;
	return 0;
}