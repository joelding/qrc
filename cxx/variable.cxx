#include <iostream> 
using namespace std; 

int main() 
{ 
	int ageForStudent; 
	double scoreForStudent; 
	char levelForStudent; 

	cout << "\nGRADE\tSCORE\tLEVEL"; 
	cout << "\n" << ageForStudent 
		<< "\t" << scoreForStudent 
		<< "\t" << levelForStudent 
		<< "\n"; 

	ageForStudent = 5; 
	scoreForStudent = 80.0; 
	levelForStudent = 'B'; 

	cout << "\nGRADE\tSCORE\tLEVEL"; 
	cout << "\n" << ageForStudent 
		<< "\t" << scoreForStudent 
		<< "\t" << levelForStudent 
		<< "\n"; 

	/* with constructor
	 */
	int ageForStudent2 = int(3); 
	double scoreForStudent2 = double(90.0); 
	char levelForStudent2 = char('A');

	cout << "\nGRADE\tSCORE\tLEVEL"; 
	cout << "\n" << ageForStudent2 
		<< "\t" << scoreForStudent2 
		<< "\t" << levelForStudent2 
		<< "\n"; 

	return 0;
}

