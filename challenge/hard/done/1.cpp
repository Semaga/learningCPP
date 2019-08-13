#include <iostream>
// #include <string>
using namespace std;


int lenghtString(char *str);
char *reverseString(char *str);
void BracketBalance(char *str);
char *insertnString(char * first_str, char *insert_str, int position);
int occurenceSubstring(char * first_str, char * hz);

int main(){
	char str[]= "cppstudio.com";
	char str1[]= "studio";
	cout<< "Длинна строки \""<< str <<"\" = " << lenghtString(str);
	cout<< "\nИвертирование строки: "<< str << "\n";
	cout<< "Результат инвертирование: "<< reverseString(str) << endl;
	char string[]= "(5+(4+a[2])+b[1]*(3-2))";
	cout<< "Введите строку для проверки баланса скобок: "<< string<< endl;
	BracketBalance(string);
	cout<< "egc:\n\n" << insertnString("cpp.com", "studio", 4)<< endl;
	cout<< "Введите строку для получения позиции подстроки: " << str<< endl;
	cout<< "Введите подстроку: " << str1 << endl;
	str = reverseString(str);
	cout<< "Номер позиции = " <<  occurenceSubstring(str, str1); 

	return 0;
}

int lenghtString(char *str){
	int lenght= 0;
	while(str[lenght]!='\0'){
		++lenght;
	}
	return lenght;
}

char *reverseString(char *string){
	int lenght = lenghtString (string); // находим длину строки
	char temp; // временная переменная для хранения переставляемого символа
	for (int counter = 0; counter < (lenght / 2); counter++){
		if (counter != (lenght - 1 - counter)){
			temp = string[lenght - 1 - counter]; 
			string[lenght - 1 - counter] = string[counter];
			string[counter] = temp;
		}
	}
	return string; // возвращаем указатель на строку
}

void BracketBalance(char *str){
	int figure= 0;
	int krugl= 0;
	int kvadr= 0;
	int check;
	for(int i= 0; str[i]!='\0'; ++i){
		if(str[i]== '{'){
			figure++;
		}else if(str[i]== '['){
			kvadr++;
		}else if(str[i]== '('){
			krugl++;
		}else if(str[i]== '}'){
			figure--;
		}else if(str[i]== ']'){
			kvadr--;
		}else if(str[i]== ')'){
			krugl--;
		}
	}

	if(figure> 0){
		cout<< "Избыток { \n"; 
	}else if(figure< 0){
		cout<< "Избыток } \n"; 
	}else{
		cout<< "Ok с {}\n";
		check++;
	}

	if(kvadr> 0){
		cout<< "Избыток [ \n"; 
	}else if(kvadr< 0){
		cout<< "Избыток ] \n"; 
	}else{
		cout<< "Ok с []\n";
		check++;
	}

	if(krugl> 0){
		cout<< "Избыток ( \n"; 
	}else if(krugl< 0){
		cout<< "Избыток ) \n"; 
	}else{
		cout<< "Ok с ()\n";
		check++;
	}

	// return check;
}

char *insertnString(char * first_str, char *insert_str, int position){
	position--;
	int lenght= 0;
	lenght+= lenghtString(first_str);
	lenght+= lenghtString(insert_str);
	char *new_str= new char[lenght];

	for(int i= 0; i<lenght; ++i){
		if(i< position){
			new_str[i]= first_str[i];
		}else if(i>= position && i< position+ lenghtString(insert_str)){
			new_str[i]= insert_str[i-position];
		}else if(i>= position+lenghtString(insert_str)){
			for(int j= position; j< lenghtString(first_str); ++i, ++j){
				new_str[i]= first_str[j];				
			}
		}

	}

	return new_str;
}

int occurenceSubstring(char * first_str, char * hz){
	int lenght_1= lenghtString(first_str);
	int lenght_2= lenghtString(hz);
	int qwe= 0;
	int position;
	
	for (int i = 0; i < lenght_1; ++i){
		if(first_str[i]== hz[0]){
			position=i;
			for (int j = 1; j < lenght_2; ++j,++i){
				if(first_str[i]== hz[j]){
					qwe++;
				}else if((qwe+1)!= lenght_2){
					j= 0;
					qwe= 0;
					position= 0;
				}else if((qwe+1)==lenght_2){
					return position; 
				}
			}
		}
	}

	// return position;
}

